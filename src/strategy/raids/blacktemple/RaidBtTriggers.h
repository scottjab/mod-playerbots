#ifndef _PLAYERBOT_RAIDBTTRIGGERS_H
#define _PLAYERBOT_RAIDBTTRIGGERS_H

#include "Trigger.h"

class BtIllidanFlameCrashTrigger : public Trigger
{
public:
    BtIllidanFlameCrashTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt illidan flame crash") {}
    bool IsActive() override;
};

class BtIllidanEyeBlastTrigger : public Trigger
{
public:
    BtIllidanEyeBlastTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt illidan eye blast") {}
    bool IsActive() override;
};

class BtNajentusTidalShieldTrigger : public Trigger
{
public:
    BtNajentusTidalShieldTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt najentus tidal shield") {}
    bool IsActive() override;
};

class BtSupremusVolcanoTrigger : public Trigger
{
public:
    BtSupremusVolcanoTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt supremus volcano") {}
    bool IsActive() override;
};

class BtGorefiendShadowOfDeathTrigger : public Trigger
{
public:
    BtGorefiendShadowOfDeathTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt gorefiend shadow of death") {}
    bool IsActive() override;
};

class BtBloodboilFelRageTrigger : public Trigger
{
public:
    BtBloodboilFelRageTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt bloodboil fel rage") {}
    bool IsActive() override;
};

class BtShahrazFatalAttractionTrigger : public Trigger
{
public:
    BtShahrazFatalAttractionTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt shahraz fatal attraction") {}
    bool IsActive() override;
};

class BtCouncilReflectiveShieldTrigger : public Trigger
{
public:
    BtCouncilReflectiveShieldTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt council reflective shield") {}
    bool IsActive() override;
};

class BtCouncilGroundAoeTrigger : public Trigger
{
public:
    BtCouncilGroundAoeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt council ground aoe") {}
    bool IsActive() override;
};

class BtIllidanAgonizingFlamesTrigger : public Trigger
{
public:
    BtIllidanAgonizingFlamesTrigger(PlayerbotAI* botAI) : Trigger(botAI, "bt illidan agonizing flames") {}
    bool IsActive() override;
};

#endif


