#ifndef _PLAYERBOT_RAIDKARASTRATEGY_H
#define _PLAYERBOT_RAIDKARASTRATEGY_H

#include "Strategy.h"

class RaidKaraStrategy : public Strategy
{
public:
    RaidKaraStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string const getName() override { return "kara"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif


