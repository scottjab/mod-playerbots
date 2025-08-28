#ifndef _PLAYERBOT_RAIDSWPSTRATEGY_H
#define _PLAYERBOT_RAIDSWPSTRATEGY_H

#include "Strategy.h"

class RaidSwpStrategy : public Strategy
{
public:
    RaidSwpStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "swp"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


