#ifndef _PLAYERBOT_RAIDSSCSTRATEGY_H
#define _PLAYERBOT_RAIDSSCSTRATEGY_H

#include "Strategy.h"

class RaidSscStrategy : public Strategy
{
public:
    RaidSscStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "ssc"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


