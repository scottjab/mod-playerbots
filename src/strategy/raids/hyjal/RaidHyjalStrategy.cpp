#include "RaidHyjalStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidHyjalStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Archimonde Doomfire: aura 31945 on fire, avoid ground
    triggers.push_back(new TriggerNode("hyjal archimonde doomfire",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));

    // Air Burst: 32014 cast -> stop casting and prepare to land safely
    triggers.push_back(new TriggerNode("hyjal archimonde air burst",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 5), nullptr)));

    // Winterchill: Death and Decay -> avoid ground
    triggers.push_back(new TriggerNode("hyjal winterchill death and decay",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Winterchill: Icebolt -> stop casting
    triggers.push_back(new TriggerNode("hyjal winterchill icebolt",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 4), nullptr)));

    // Anetheron: Carrion Swarm -> move from group
    triggers.push_back(new TriggerNode("hyjal anetheron carrion swarm",
        NextAction::array(0, new NextAction("move from group", ACTION_RAID + 3), nullptr)));

    // Kaz'rogal: Mark -> prepare defensives
    triggers.push_back(new TriggerNode("hyjal kazrogal mark",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 2), nullptr)));

    // Azgalor: Doom -> avoid aoe and prioritize survival
    triggers.push_back(new TriggerNode("hyjal azgalor doom",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));
}

void RaidHyjalStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


