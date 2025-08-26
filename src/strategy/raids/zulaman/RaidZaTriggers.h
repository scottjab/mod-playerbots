#ifndef _PLAYERBOT_RAIDZATRIGGERS_H
#define _PLAYERBOT_RAIDZATRIGGERS_H

#include "Trigger.h"

// Akil'zon
class ZaAkilzonElectricalStormTrigger : public Trigger
{
public:
    ZaAkilzonElectricalStormTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za akilzon electrical storm") {}
    bool IsActive() override;
};

class ZaStaticDisruptionTrigger : public Trigger
{
public:
    ZaStaticDisruptionTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za static disruption") {}
    bool IsActive() override;
};

// Nalorakk
class ZaNalorakkMangleOnTankTrigger : public Trigger
{
public:
    ZaNalorakkMangleOnTankTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za nalorakk mangle on tank") {}
    bool IsActive() override;
};

// Jan'alai
class ZaJanalaiFireBombsTrigger : public Trigger
{
public:
    ZaJanalaiFireBombsTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za janalai fire bombs") {}
    bool IsActive() override;
};

class ZaJanalaiFlameBreathTrigger : public Trigger
{
public:
    ZaJanalaiFlameBreathTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za janalai flame breath") {}
    bool IsActive() override;
};

// Halazzi
class ZaHalazziTotemTrigger : public Trigger
{
public:
    ZaHalazziTotemTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za halazzi totem") {}
    bool IsActive() override;
};

// Zul'jin
class ZaZuljinCreepingParalysisTrigger : public Trigger
{
public:
    ZaZuljinCreepingParalysisTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za zuljin creeping paralysis") {}
    bool IsActive() override;
};

class ZaZuljinEnergyStormTrigger : public Trigger
{
public:
    ZaZuljinEnergyStormTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za zuljin energy storm") {}
    bool IsActive() override;
};

class ZaZuljinClawRageTrigger : public Trigger
{
public:
    ZaZuljinClawRageTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za zuljin claw rage") {}
    bool IsActive() override;
};

class ZaZuljinFlamePillarsTrigger : public Trigger
{
public:
    ZaZuljinFlamePillarsTrigger(PlayerbotAI* botAI) : Trigger(botAI, "za zuljin flame pillars") {}
    bool IsActive() override;
};

#endif


