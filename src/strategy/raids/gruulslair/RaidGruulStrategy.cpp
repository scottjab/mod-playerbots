#include "RaidGruulStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidGruulStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Ground Slam -> Shatter handling: spread before shatter, avoid others on shatter
    triggers.push_back(new TriggerNode("gruul ground slam",
        NextAction::array(0, new NextAction("move from group", ACTION_EMERGENCY + 3), nullptr)));

    triggers.push_back(new TriggerNode("gruul shatter",
        NextAction::array(0, new NextAction("move from group", ACTION_EMERGENCY + 5), nullptr)));

    // Hurtful Strike: off-tanks should be near boss; melee dps avoid highest threat if not tank
}

void RaidGruulStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


