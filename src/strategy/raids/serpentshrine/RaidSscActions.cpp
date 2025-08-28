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
        for (ObjectGuid guid : npcs)
            if (Unit* u = botAI->GetUnit(guid))
                if (u->IsAlive())
                    return Attack(u);
    }
    return false;
}


