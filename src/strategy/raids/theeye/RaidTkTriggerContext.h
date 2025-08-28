#ifndef _PLAYERBOT_RAIDTKTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDTKTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidTkTriggers.h"

class RaidTkTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidTkTriggerContext()
    {
        creators["tk kael gravity lapse"] = &RaidTkTriggerContext::gravity_lapse;
        creators["tk kael flame strike"] = &RaidTkTriggerContext::flame_strike;
        creators["tk vr pounding"] = &RaidTkTriggerContext::vr_pounding;
        creators["tk vr arcane orb"] = &RaidTkTriggerContext::vr_arcane_orb;
        creators["tk solarian wrath"] = &RaidTkTriggerContext::solarian_wrath;
        creators["tk solarian blinding light"] = &RaidTkTriggerContext::solarian_blinding;
        creators["tk kael mind control"] = &RaidTkTriggerContext::kael_mc;
        creators["tk kael phoenix"] = &RaidTkTriggerContext::kael_phoenix;
    }

private:
    static Trigger* gravity_lapse(PlayerbotAI* ai) { return new TkKaelGravityLapseTrigger(ai); }
    static Trigger* flame_strike(PlayerbotAI* ai) { return new TkKaelFlameStrikeTrigger(ai); }
    static Trigger* vr_pounding(PlayerbotAI* ai) { return new TkVrPoundingTrigger(ai); }
    static Trigger* vr_arcane_orb(PlayerbotAI* ai) { return new TkVrArcaneOrbTrigger(ai); }
    static Trigger* solarian_wrath(PlayerbotAI* ai) { return new TkSolarianWrathTrigger(ai); }
    static Trigger* solarian_blinding(PlayerbotAI* ai) { return new TkSolarianBlindingLightTrigger(ai); }
    static Trigger* kael_mc(PlayerbotAI* ai) { return new TkKaelMindControlTrigger(ai); }
    static Trigger* kael_phoenix(PlayerbotAI* ai) { return new TkKaelPhoenixTrigger(ai); }
};

#endif


