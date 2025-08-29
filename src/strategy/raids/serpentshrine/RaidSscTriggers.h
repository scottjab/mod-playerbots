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

class SscKarathressEncounterTrigger : public Trigger
{
public:
    SscKarathressEncounterTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress encounter") {}
    bool IsActive() override;
};

class SscKarathressTotemSpawnedTrigger : public Trigger
{
public:
    SscKarathressTotemSpawnedTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress totem") {}
    bool IsActive() override;
};

class SscKarathressSearNovaTrigger : public Trigger
{
public:
    SscKarathressSearNovaTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress sear nova") {}
    bool IsActive() override;
};

class SscKarathressPowerTrigger : public Trigger
{
public:
    SscKarathressPowerTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress power") {}
    bool IsActive() override;
};

class SscKarathressBlessingTrigger : public Trigger
{
public:
    SscKarathressBlessingTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress blessing") {}
    bool IsActive() override;
};

class SscKarathressCataclysmicBoltTrigger : public Trigger
{
public:
    SscKarathressCataclysmicBoltTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc karathress cataclysmic bolt") {}
    bool IsActive() override;
};

class SscCaribdisCycloneTrigger : public Trigger
{
public:
    SscCaribdisCycloneTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc caribdis cyclone") {}
    bool IsActive() override;
};

class SscCaribdisTidalSurgeTrigger : public Trigger
{
public:
    SscCaribdisTidalSurgeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc caribdis tidal surge") {}
    bool IsActive() override;
};

class SscSharkkisEnrageTrigger : public Trigger
{
public:
    SscSharkkisEnrageTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc sharkkis enrage") {}
    bool IsActive() override;
};

class SscVashjStaticChargeTrigger : public Trigger
{
public:
    SscVashjStaticChargeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj static charge") {}
    bool IsActive() override;
};

class SscVashjEntangleTrigger : public Trigger
{
public:
    SscVashjEntangleTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj entangle") {}
    bool IsActive() override;
};

class SscVashjShockBlastTrigger : public Trigger
{
public:
    SscVashjShockBlastTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj shock blast") {}
    bool IsActive() override;
};

class SscVashjToxicSporesTrigger : public Trigger
{
public:
    SscVashjToxicSporesTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj toxic spores") {}
    bool IsActive() override;
};

class SscVashjPhase3Trigger : public Trigger
{
public:
    SscVashjPhase3Trigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj phase3") {}
    bool IsActive() override;
};

class SscVashjAddPhaseTrigger : public Trigger
{
public:
    SscVashjAddPhaseTrigger(PlayerbotAI* botAI) : Trigger(botAI, "ssc vashj add phase") {}
    bool IsActive() override;
};

#endif


