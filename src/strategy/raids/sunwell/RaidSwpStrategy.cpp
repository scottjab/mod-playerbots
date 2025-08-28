#include "RaidSwpStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidSwpStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Kil'jaeden: Darkness of a Thousand Souls 46605/45657 -> defensive and avoid
    triggers.push_back(new TriggerNode("swp kj darkness",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 6), new NextAction("use trinket", ACTION_EMERGENCY + 2), nullptr)));

    // Kil'jaeden: Armageddon periodic 45921 / missile 45909 -> avoid ground
    triggers.push_back(new TriggerNode("swp kj armageddon",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));
}

void RaidSwpStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


