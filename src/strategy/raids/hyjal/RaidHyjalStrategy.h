#ifndef _PLAYERBOT_RAIDHYJALSTRATEGY_H
#define _PLAYERBOT_RAIDHYJALSTRATEGY_H

#include "Strategy.h"

class RaidHyjalStrategy : public Strategy
{
public:
    RaidHyjalStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "hyjal"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


