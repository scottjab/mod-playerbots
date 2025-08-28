#ifndef _PLAYERBOT_RAIDSSCTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDSSCTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidSscTriggers.h"

class RaidSscTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidSscTriggerContext()
    {
        creators["ssc morogrim earthquake"] = &RaidSscTriggerContext::morogrim_quake;
        creators["ssc hydross mark"] = &RaidSscTriggerContext::hydross_mark;
        creators["ssc lurker spout"] = &RaidSscTriggerContext::lurker_spout;
        creators["ssc leotheras whirlwind"] = &RaidSscTriggerContext::leotheras_whirlwind;
        creators["ssc karathress caribdis cast"] = &RaidSscTriggerContext::karathress_caribdis;
        creators["ssc karathress totem"] = &RaidSscTriggerContext::karathress_totem;
        creators["ssc vashj add phase"] = &RaidSscTriggerContext::vashj_add_phase;
    }

private:
    static Trigger* morogrim_quake(PlayerbotAI* ai) { return new SscMorogrimEarthquakeTrigger(ai); }
    static Trigger* hydross_mark(PlayerbotAI* ai) { return new SscHydrossMarkTrigger(ai); }
    static Trigger* lurker_spout(PlayerbotAI* ai) { return new SscLurkerSpoutTrigger(ai); }
    static Trigger* leotheras_whirlwind(PlayerbotAI* ai) { return new SscLeotherasWhirlwindTrigger(ai); }
    static Trigger* karathress_caribdis(PlayerbotAI* ai) { return new SscKarathressCaribdisCastTrigger(ai); }
    static Trigger* karathress_totem(PlayerbotAI* ai) { return new SscKarathressTotemSpawnedTrigger(ai); }
    static Trigger* vashj_add_phase(PlayerbotAI* ai) { return new SscVashjAddPhaseTrigger(ai); }
};

#endif


