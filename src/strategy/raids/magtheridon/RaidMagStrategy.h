#ifndef _PLAYERBOT_RAIDMAGSTRATEGY_H
#define _PLAYERBOT_RAIDMAGSTRATEGY_H

#include "Strategy.h"

class RaidMagStrategy : public Strategy
{
public:
    RaidMagStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "magtheridon"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


