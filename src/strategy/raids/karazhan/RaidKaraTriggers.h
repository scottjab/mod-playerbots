#ifndef _PLAYERBOT_RAIDKARATRIGGERS_H
#define _PLAYERBOT_RAIDKARATRIGGERS_H

#include "Trigger.h"

class KaraCuratorEvocateTrigger : public Trigger
{
public:
    KaraCuratorEvocateTrigger(PlayerbotAI* botAI);
    bool IsActive() override;
};

class KaraAranAoeTrigger : public Trigger
{
public:
    KaraAranAoeTrigger(PlayerbotAI* botAI);
    bool IsActive() override;
};

class KaraMalchezaarInfernalTrigger : public Trigger
{
public:
    KaraMalchezaarInfernalTrigger(PlayerbotAI* botAI);
    bool IsActive() override;
};

#endif


