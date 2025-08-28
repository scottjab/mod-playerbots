#ifndef _PLAYERBOT_RAIDMAGTRIGGERS_H
#define _PLAYERBOT_RAIDMAGTRIGGERS_H

#include "Trigger.h"

class MagQuakeTrigger : public Trigger
{
public:
    MagQuakeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "mag quake") {}
    bool IsActive() override;
};

class MagBlastNovaTrigger : public Trigger
{
public:
    MagBlastNovaTrigger(PlayerbotAI* botAI) : Trigger(botAI, "mag blast nova") {}
    bool IsActive() override;
};

class MagDebrisTrigger : public Trigger
{
public:
    MagDebrisTrigger(PlayerbotAI* botAI) : Trigger(botAI, "mag debris") {}
    bool IsActive() override;
};

#endif


