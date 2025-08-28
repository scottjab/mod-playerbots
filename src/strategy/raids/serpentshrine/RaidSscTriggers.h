#ifndef _PLAYERBOT_RAIDSSCTRIGGERS_H
#define _PLAYERBOT_RAIDSSCTRIGGERS_H

#include "Trigger.h"

class SscMorogrimEarthquakeTrigger : public Trigger
{
public:
    SscMorogrimEarthquakeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc morogrim earthquake") {}
    bool IsActive() override;
};

class SscHydrossMarkTrigger : public Trigger
{
public:
    SscHydrossMarkTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc hydross mark") {}
    bool IsActive() override;
};

class SscLurkerSpoutTrigger : public Trigger
{
public:
    SscLurkerSpoutTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc lurker spout") {}
    bool IsActive() override;
};

class SscLeotherasWhirlwindTrigger : public Trigger
{
public:
    SscLeotherasWhirlwindTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc leotheras whirlwind") {}
    bool IsActive() override;
};

class SscKarathressCaribdisCastTrigger : public Trigger
{
public:
    SscKarathressCaribdisCastTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress caribdis cast") {}
    bool IsActive() override;
};

class SscKarathressTotemSpawnedTrigger : public Trigger
{
public:
    SscKarathressTotemSpawnedTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress totem") {}
    bool IsActive() override;
};

class SscVashjAddPhaseTrigger : public Trigger
{
public:
    SscVashjAddPhaseTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj add phase") {}
    bool IsActive() override;
};

#endif


