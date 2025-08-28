#ifndef _PLAYERBOT_RAIDBTSTRATEGY_H
#define _PLAYERBOT_RAIDBTSTRATEGY_H

#include "Strategy.h"

class RaidBtStrategy : public Strategy
{
public:
    RaidBtStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "bt"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


