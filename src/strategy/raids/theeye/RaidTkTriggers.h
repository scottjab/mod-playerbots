#ifndef _PLAYERBOT_RAIDTKTRIGGERS_H
#define _PLAYERBOT_RAIDTKTRIGGERS_H

#include "Trigger.h"

class TkKaelGravityLapseTrigger : public Trigger
{
public:
    TkKaelGravityLapseTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk kael gravity lapse") {}
    bool IsActive() override;
};

class TkKaelFlameStrikeTrigger : public Trigger
{
public:
    TkKaelFlameStrikeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk kael flame strike") {}
    bool IsActive() override;
};

class TkVrPoundingTrigger : public Trigger
{
public:
    TkVrPoundingTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk vr pounding") {}
    bool IsActive() override;
};

class TkVrArcaneOrbTrigger : public Trigger
{
public:
    TkVrArcaneOrbTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk vr arcane orb") {}
    bool IsActive() override;
};

class TkSolarianWrathTrigger : public Trigger
{
public:
    TkSolarianWrathTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk solarian wrath") {}
    bool IsActive() override;
};

class TkSolarianBlindingLightTrigger : public Trigger
{
public:
    TkSolarianBlindingLightTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk solarian blinding light") {}
    bool IsActive() override;
};

class TkKaelMindControlTrigger : public Trigger
{
public:
    TkKaelMindControlTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk kael mind control") {}
    bool IsActive() override;
};

class TkKaelPhoenixTrigger : public Trigger
{
public:
    TkKaelPhoenixTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tk kael phoenix") {}
    bool IsActive() override;
};

#endif


