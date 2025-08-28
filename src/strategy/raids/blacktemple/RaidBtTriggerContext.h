#ifndef _PLAYERBOT_RAIDBTTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDBTTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidBtTriggers.h"

class RaidBtTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidBtTriggerContext()
    {
        creators["bt illidan flame crash"] = &RaidBtTriggerContext::flame_crash;
        creators["bt illidan eye blast"] = &RaidBtTriggerContext::eye_blast;
        creators["bt najentus tidal shield"] = &RaidBtTriggerContext::najentus_shield;
        creators["bt supremus volcano"] = &RaidBtTriggerContext::supremus_volcano;
        creators["bt gorefiend shadow of death"] = &RaidBtTriggerContext::gorefiend_sod;
        creators["bt bloodboil fel rage"] = &RaidBtTriggerContext::bloodboil_fel;
        creators["bt shahraz fatal attraction"] = &RaidBtTriggerContext::shahraz_fatal;
        creators["bt council reflective shield"] = &RaidBtTriggerContext::council_reflect;
        creators["bt council ground aoe"] = &RaidBtTriggerContext::council_ground_aoe;
        creators["bt illidan agonizing flames"] = &RaidBtTriggerContext::illidan_flames;
    }

private:
    static Trigger* flame_crash(PlayerbotAI* ai) { return new BtIllidanFlameCrashTrigger(ai); }
    static Trigger* eye_blast(PlayerbotAI* ai) { return new BtIllidanEyeBlastTrigger(ai); }
    static Trigger* najentus_shield(PlayerbotAI* ai) { return new BtNajentusTidalShieldTrigger(ai); }
    static Trigger* supremus_volcano(PlayerbotAI* ai) { return new BtSupremusVolcanoTrigger(ai); }
    static Trigger* gorefiend_sod(PlayerbotAI* ai) { return new BtGorefiendShadowOfDeathTrigger(ai); }
    static Trigger* bloodboil_fel(PlayerbotAI* ai) { return new BtBloodboilFelRageTrigger(ai); }
    static Trigger* shahraz_fatal(PlayerbotAI* ai) { return new BtShahrazFatalAttractionTrigger(ai); }
    static Trigger* council_reflect(PlayerbotAI* ai) { return new BtCouncilReflectiveShieldTrigger(ai); }
    static Trigger* council_ground_aoe(PlayerbotAI* ai) { return new BtCouncilGroundAoeTrigger(ai); }
    static Trigger* illidan_flames(PlayerbotAI* ai) { return new BtIllidanAgonizingFlamesTrigger(ai); }
};

#endif


