#include "RaidMagStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidMagStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Quake: stop casting and spread
    triggers.push_back(new TriggerNode("mag quake",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 6), new NextAction("move from group", ACTION_EMERGENCY + 4), nullptr)));

    // Blast Nova: interrupt if possible, otherwise defensive cooldowns
    triggers.push_back(new TriggerNode("mag blast nova",
        NextAction::array(0, new NextAction("interrupt", ACTION_INTERRUPT + 6), new NextAction("use trinket", ACTION_EMERGENCY + 2), nullptr)));

    // Debris: avoid AoE
    triggers.push_back(new TriggerNode("mag debris",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));
}

void RaidMagStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


