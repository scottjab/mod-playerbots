/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license
 */

#include "WintergraspActions.h"

#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Event.h"
#include "Opcodes.h"
#include "Player.h"
#include "Playerbots.h"
#include "WorldPacket.h"
#include "World.h"

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
    if (!bot->IsInWorld())
        return false;

    // Zone check: WG area id
    if (bot->GetZoneId() != AREA_WINTERGRASP)
        return false;

    // Level requirement
    if (bot->GetLevel() < sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL))
        return false;

    // Already in battle or queued
    if (bot->InBattleground() || bot->GetMapId() == MAP_NORTHREND && bot->GetZoneId() == AREA_WINTERGRASP && bot->GetBattleground())
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
        return true;
    }

    // Otherwise request to be queued (respond to queue invite proactively)
    WorldPacket p(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, 5);
    p << uint32(BATTLEFIELD_BATTLEID_WG) << uint8(1);
    bot->GetSession()->HandleBfQueueInviteResponse(p);
    return true;
}


