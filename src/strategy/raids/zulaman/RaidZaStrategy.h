#ifndef _PLAYERBOT_RAIDZASTRATEGY_H
#define _PLAYERBOT_RAIDZASTRATEGY_H

#include "Strategy.h"

class RaidZaStrategy : public Strategy
{
public:
    RaidZaStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "za"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


