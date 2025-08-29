#include "RaidSscActions.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Attack Vashj adds: prioritize Strider(22056) > Elite(22055) > Elemental(21958/22207)
bool RaidSscAttackVashjAddAction::Execute(Event /*event*/)
{
    static const std::vector<std::string> priorities = { "22056", "22055", "21958", "22207" };
    for (auto const& entry : priorities)
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", entry);
        for (ObjectGuid guid : npcs)
            if (Unit* u = botAI->GetUnit(guid))
                if (u->IsAlive())
                    return Attack(u);
    }
    return false;
}

// Lurker: maintain rear flank to avoid frontal spout cone
bool RaidSscRearFlankLurkerAction::Execute(Event /*event*/)
{
    return botAI->DoSpecificAction("rear flank");
}

// Karathress: interrupt Caribdis (21964) heals and cyclone if in range
bool RaidSscInterruptCaribdisAction::Execute(Event /*event*/)
{
    Unit* caribdis = AI_VALUE2(Unit*, "find target", "caribdis");
    if (!caribdis)
        return false;
    return botAI->DoSpecificAction("interrupt");
}

// Karathress Totems: Spitfire(22091) > Earthbind(22486) > Poison Cleansing(22487)
bool RaidSscAttackKarathressTotemAction::Execute(Event /*event*/)
{
    static const std::vector<std::string> priorities = { "22091", "22486", "22487" };
    for (auto const& entry : priorities)
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", entry);
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
            LOG_INFO("playerbots", "[Raid][SSC] Karathress totem scan: entry {} -> {} nearby", entry, npcs.size());
        for (ObjectGuid guid : npcs)
        {
            if (Unit* u = botAI->GetUnit(guid))
            {
                if (u->IsAlive())
                {
                    // Avoid pulling from far away rooms
                    float dist = bot->GetDistance(u);
                    if (dist > 60.0f)
                    {
                        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                            LOG_INFO("playerbots", "[Raid][SSC] Skipping totem {} at distance {} (>60)", entry, dist);
                        continue;
                    }
                    if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                        LOG_INFO("playerbots", "[Raid][SSC] Attacking Karathress totem {} at distance {}", entry, dist);
                    bool attacked = Attack(u);
                    if (!attacked && (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT)))
                        LOG_INFO("playerbots", "[Raid][SSC] Attack call on totem {} returned false", entry);
                    return attacked;
                }
                else if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                {
                    LOG_INFO("playerbots", "[Raid][SSC] Found totem {} but it is dead (guid={})", entry, guid.ToString());
                }
            }
            else if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
            {
                LOG_INFO("playerbots", "[Raid][SSC] Nearby totem guid could not be resolved (entry {}, guid={})", entry, guid.ToString());
            }
        }
    }
    if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
        LOG_INFO("playerbots", "[Raid][SSC] No valid Karathress totems to attack (none alive or in range)");
    return false;
}

// Karathress: focus priority per strat – Sharkkis > Tidalvess > Caribdis; then Karathress
bool RaidSscAttackKarathressTargetAction::Execute(Event /*event*/)
{
    // Recommended kill order per strat: Tidalvess (Shaman) > Caribdis (Priest) > Sharkkis (Hunter) > Karathress
    static const std::vector<std::string> priorities = { "tidalvess", "caribdis", "sharkkis", "karathress" };
    for (auto const& name : priorities)
    {
        Unit* u = AI_VALUE2(Unit*, "find target", name);
        if (!u || !u->IsAlive())
            continue;
        if (bot->GetDistance(u) > 80.0f)
            continue;
        return Attack(u);
    }
    return false;
}


