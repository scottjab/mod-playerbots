#ifndef _PLAYERBOT_RAIDSWPTRIGGERS_H
#define _PLAYERBOT_RAIDSWPTRIGGERS_H

#include "Trigger.h"

class SwpKjDarknessTrigger : public Trigger
{
public:
    SwpKjDarknessTrigger(PlayerbotAI* botAI) : Trigger(botAI, "swp kj darkness") {}
    bool IsActive() override;
};

class SwpKjArmageddonTrigger : public Trigger
{
public:
    SwpKjArmageddonTrigger(PlayerbotAI* botAI) : Trigger(botAI, "swp kj armageddon") {}
    bool IsActive() override;
};

#endif


