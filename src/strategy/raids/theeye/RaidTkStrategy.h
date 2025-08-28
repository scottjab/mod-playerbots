#ifndef _PLAYERBOT_RAIDTKSTRATEGY_H
#define _PLAYERBOT_RAIDTKSTRATEGY_H

#include "Strategy.h"

class RaidTkStrategy : public Strategy
{
public:
    RaidTkStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "tk"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


