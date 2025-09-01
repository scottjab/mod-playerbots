#include "RaidSscActions.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Attack Vashj adds: prioritize Strider(22056) > Elite(22055) > Elemental(21958/22207)
bool RaidSscAttackVashjAddAction::Execute(Event /*event*/)
{
    // Updated with DBM-aligned priority: Tainted Elemental (22009) first, then Strider, Elite, Enchanted/Other elementals
    static const std::vector<std::string> priorities = { "22009", "22056", "22055", "21958", "22207" };
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
bool RaidSscInterruptCaribdisAction::Execute(Event event)
{
    // Prefer entry-based lookup for robustness (Caribdis 21964)
    GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", "21964");
    for (ObjectGuid guid : npcs)
        if (Unit* caribdis = botAI->GetUnit(guid))
            if (caribdis->IsAlive() && bot->GetDistance(caribdis) < 40.0f)
            {
                // Try class-appropriate interrupt actions; run silently to avoid "unknown action" spam
                std::vector<std::string> interruptActions;
                switch (bot->getClass())
                {
                    case CLASS_SHAMAN:
                        interruptActions = { "wind shear", "earth shock" };
                        break;
                    case CLASS_ROGUE:
                        interruptActions = { "kick" };
                        break;
                    case CLASS_WARRIOR:
                        interruptActions = { "pummel", "shield bash" };
                        break;
                    case CLASS_MAGE:
                        interruptActions = { "counterspell" };
                        break;
                    case CLASS_DEATH_KNIGHT:
                        interruptActions = { "mind freeze" };
                        break;
                    case CLASS_PRIEST:
                        interruptActions = { "silence" };
                        break;
                    case CLASS_HUNTER:
                        interruptActions = { "silencing shot" };
                        break;
                    case CLASS_PALADIN:
                        interruptActions = { "hammer of justice" };
                        break;
                    case CLASS_DRUID:
                        interruptActions = { "bash", "maim" };
                        break;
                    default:
                        break;
                }
                // Also include a generic fallback list in case specialization actions are available
                std::vector<std::string> genericFallback = { "kick", "pummel", "shield bash", "wind shear", "counterspell", "mind freeze", "silence", "silencing shot" };
                interruptActions.insert(interruptActions.end(), genericFallback.begin(), genericFallback.end());

                for (std::string const& name : interruptActions)
                    if (botAI->DoSpecificAction(name, event, true))
                        return true;

                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                    LOG_DEBUG("playerbots", "[Raid][SSC] No usable interrupt action for class {}", bot->getClass());
                return false;
            }
    return false;
}

// Karathress Totems: Spitfire(22091) > Earthbind(22486) > Poison Cleansing(22487)
bool RaidSscAttackKarathressTotemAction::Execute(Event /*event*/)
{
    static const std::vector<std::string> priorities = { "22091", "22486", "22487" };
    for (auto const& entry : priorities)
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", entry);
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
            LOG_DEBUG("playerbots", "[Raid][SSC] Karathress totem scan: entry {} -> {} nearby", entry, npcs.size());
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
                            LOG_DEBUG("playerbots", "[Raid][SSC] Skipping totem {} at distance {} (>60)", entry, dist);
                        continue;
                    }
                    if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                        LOG_DEBUG("playerbots", "[Raid][SSC] Attacking Karathress totem {} at distance {}", entry, dist);
                    bool attacked = Attack(u);
                    if (!attacked && (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT)))
                        LOG_DEBUG("playerbots", "[Raid][SSC] Attack call on totem {} returned false", entry);
                    return attacked;
                }
                else if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
                {
                    LOG_DEBUG("playerbots", "[Raid][SSC] Found totem {} but it is dead (guid={})", entry, guid.ToString());
                }
            }
            else if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
            {
                LOG_DEBUG("playerbots", "[Raid][SSC] Nearby totem guid could not be resolved (entry {}, guid={})", entry, guid.ToString());
            }
        }
    }
    if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT) || botAI->HasStrategy("debug", BOT_STATE_COMBAT))
        LOG_DEBUG("playerbots", "[Raid][SSC] No valid Karathress totems to attack (none alive or in range)");
    return false;
}

// Karathress: focus priority per strat – Sharkkis > Tidalvess > Caribdis; then Karathress
bool RaidSscAttackKarathressTargetAction::Execute(Event /*event*/)
{
    // Recommended kill order per strat: Tidalvess (Shaman) > Caribdis (Priest) > Sharkkis (Hunter) > Karathress
    // Entries: Tidalvess 21965, Caribdis 21964, Sharkkis 21966, Karathress 21214
    static const std::vector<std::string> priorities = { "21965", "21964", "21966", "21214" };
    for (auto const& entry : priorities)
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", entry);
        for (ObjectGuid guid : npcs)
            if (Unit* u = botAI->GetUnit(guid))
                if (u->IsAlive())
                {
                    if (bot->GetDistance(u) > 80.0f)
                        continue;
                    return Attack(u);
                }
    }
    return false;
}


