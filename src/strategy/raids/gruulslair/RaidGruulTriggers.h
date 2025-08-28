#ifndef _PLAYERBOT_RAIDGRUULTRIGGERS_H
#define _PLAYERBOT_RAIDGRUULTRIGGERS_H

#include "Trigger.h"

class GruulGroundSlamTrigger : public Trigger
{
public:
    GruulGroundSlamTrigger(PlayerbotAI* botAI) : Trigger(botAI, "gruul ground slam") {}
    bool IsActive() override;
};

class GruulShatterTrigger : public Trigger
{
public:
    GruulShatterTrigger(PlayerbotAI* botAI) : Trigger(botAI, "gruul shatter") {}
    bool IsActive() override;
};

#endif


