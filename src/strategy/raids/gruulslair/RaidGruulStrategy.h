#ifndef _PLAYERBOT_RAIDGRUULSTRATEGY_H
#define _PLAYERBOT_RAIDGRUULSTRATEGY_H

#include "Strategy.h"

class RaidGruulStrategy : public Strategy
{
public:
    RaidGruulStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "gruul"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


