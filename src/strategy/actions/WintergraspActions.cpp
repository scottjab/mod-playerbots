/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license
 */

#include "WintergraspActions.h"

#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Event.h"
#include "Opcodes.h"
#include "Player.h"
#include "Playerbots.h"
#include "WorldPacket.h"
#include "World.h"
#include "PlayerbotAIConfig.h"
#include "MovementActions.h"
#include "PositionValue.h"

// Auto-accept Wintergrasp queue invite
bool WgAcceptQueueInviteAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Bot {} {}:{} <{}>: Accepting Wintergrasp queue invite", bot->GetGUID().ToString().c_str(),
             bot->GetTeamId() == TEAM_ALLIANCE ? "A" : "H", bot->GetLevel(), bot->GetName());
    // CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE: uint32 BattleId, uint8 Accepted
    uint32 battleId = BATTLEFIELD_BATTLEID_WG;
    uint8 accepted = 1;

    WorldPacket p(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, 5);
    p << uint32(battleId);
    p << uint8(accepted);
    bot->GetSession()->HandleBfQueueInviteResponse(p);
    return true;
}

// Auto-accept Wintergrasp entry invite (when war is active)
bool WgAcceptEntryInviteAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Bot {} {}:{} <{}>: Accepting Wintergrasp entry invite", bot->GetGUID().ToString().c_str(),
             bot->GetTeamId() == TEAM_ALLIANCE ? "A" : "H", bot->GetLevel(), bot->GetName());
    // CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE: uint32 BattleId, uint8 Accepted
    uint32 battleId = BATTLEFIELD_BATTLEID_WG;
    uint8 accepted = 1;

    WorldPacket p(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, 5);
    p << uint32(battleId);
    p << uint8(accepted);
    bot->GetSession()->HandleBfEntryInviteResponse(p);
    return true;
}

// If bot is in Wintergrasp zone and eligible, ensure they are queued/entering
bool WgEnsureQueuedAction::isUseful()
{
    if (!sPlayerbotAIConfig->wintergraspEnable)
        return false;
    if (!bot->IsInWorld())
        return false;

    // Zone check: WG area id
    if (bot->GetZoneId() != AREA_WINTERGRASP)
        return false;

    // Level requirement
    if (bot->GetLevel() < sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL))
        return false;

    // Already in battle or queued
    if (bot->InBattleground() || (bot->GetMapId() == MAP_NORTHREND && bot->GetZoneId() == AREA_WINTERGRASP && bot->GetBattleground()))
        return false;

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG))
    {
        if (!bf->IsEnabled())
            return false;
        // If already registered in war list, skip
        // We cannot easily check membership from here; rely on lack of queue/war session
    }

    return true;
}

bool WgEnsureQueuedAction::Execute(Event /*event*/)
{
    Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
    if (!bf || !bf->IsEnabled())
        return false;

    // If wartime, try entry invite path in case client missed packet
    if (bf->IsWarTime())
    {
        WorldPacket p(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, 5);
        p << uint32(BATTLEFIELD_BATTLEID_WG) << uint8(1);
        bot->GetSession()->HandleBfEntryInviteResponse(p);

        // If not in WG zone, proactively move a subset of random bots into the battle area
        if (bot->GetZoneId() != AREA_WINTERGRASP && sRandomPlayerbotMgr->IsRandomBot(bot))
        {
            // Limit mass teleports: ~3% chance per tick per eligible bot
            if (urand(0, 99) < 3)
            {
                TeamId defenderTeam = TEAM_NEUTRAL;
                if (auto* wgbf = dynamic_cast<BattlefieldWG*>(bf))
                    defenderTeam = wgbf->GetDefenderTeam();

                // Choose a spawn point based on team role (attacker vs defender)
                // Defender: near fortress
                // Attacker: near southern workshops
                float x = 4585.57f, y = 2656.52f, z = 379.22f; // central safe fallback
                if (defenderTeam != TEAM_NEUTRAL)
                {
                    if (bot->GetTeamId() == defenderTeam)
                    {
                        // Fortress vicinity
                        x = 5333.18f; y = 2840.28f; z = 409.323f;
                    }
                    else
                    {
                        // Attacker staging around Sunken Ring or South
                        if (urand(0, 1)) { x = 4932.04f; y = 2440.23f; z = 320.26f; } // Sunken Ring
                        else { x = 4774.71f; y = 2045.71f; z = 425.764f; } // Glacial Falls
                    }
                }

                bot->TeleportTo(MAP_NORTHREND, x, y, z, 0.0f);
                LOG_INFO("playerbots", "Bot {} {}:{} <{}>: Teleport to Wintergrasp for wartime",
                         bot->GetGUID().ToString().c_str(), bot->GetTeamId() == TEAM_ALLIANCE ? "A" : "H",
                         bot->GetLevel(), bot->GetName());
            }
        }
        return true;
    }

    // Otherwise request to be queued (respond to queue invite proactively)
    WorldPacket p(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, 5);
    p << uint32(BATTLEFIELD_BATTLEID_WG) << uint8(1);
    bot->GetSession()->HandleBfQueueInviteResponse(p);
    return true;
}

bool WgSelectObjectiveAction::isUseful()
{
    if (!sPlayerbotAIConfig->wintergraspEnable)
        return false;
    if (!bot->InBattleground() && bot->GetZoneId() != AREA_WINTERGRASP)
        return false;
    Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
    return bf && bf->IsEnabled();
}

bool WgSelectObjectiveAction::Execute(Event /*event*/)
{
    auto& posMap = botAI->GetAiObjectContext()->GetValue<PositionMap&>("position")->Get();
    PositionInfo pos = posMap["bg objective"]; // reuse key for WG objective

    // Default fallback: central bridge area
    pos.Reset();
    pos.Set(4689.69f, 2878.61f, 387.427f, MAP_NORTHREND);

    if (auto* wgbf = dynamic_cast<BattlefieldWG*>(sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG)))
    {
        bool wartime = wgbf->IsWarTime();
        TeamId def = wgbf->GetDefenderTeam();
        TeamId my = bot->GetTeamId();
        if (wartime)
        {
            if (my == def)
            {
                if (urand(0, 1)) { pos.Set(4464.35f, 1946.13f, 465.731f, MAP_NORTHREND); }
                else { pos.Set(4419.02f, 2802.62f, 412.714f, MAP_NORTHREND); }
            }
            else
            {
                if (urand(0, 1)) { pos.Set(4932.04f, 2440.23f, 320.26f, MAP_NORTHREND); }
                else { pos.Set(4379.6f, 2348.2f, 377.789f, MAP_NORTHREND); }
            }
        }
    }

    posMap["bg objective"] = pos;
    return true;
}

bool WgMoveToObjectiveAction::isUseful()
{
    if (!sPlayerbotAIConfig->wintergraspEnable)
        return false;
    if (!bot->InBattleground() && bot->GetZoneId() != AREA_WINTERGRASP)
        return false;
    return true;
}

bool WgMoveToObjectiveAction::Execute(Event /*event*/)
{
    auto& posMap = botAI->GetAiObjectContext()->GetValue<PositionMap&>("position")->Get();
    PositionInfo pos = posMap["bg objective"];
    if (!pos.isSet())
        return false;
    return MoveTo(pos.mapId, pos.x, pos.y, pos.z, false, true);
}


