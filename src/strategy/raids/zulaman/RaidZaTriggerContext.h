#ifndef _PLAYERBOT_RAIDZATRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDZATRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidZaTriggers.h"

class RaidZaTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidZaTriggerContext()
    {
        creators["za akilzon electrical storm"] = &RaidZaTriggerContext::akilzon_storm;
        creators["za static disruption"] = &RaidZaTriggerContext::static_disruption;
        creators["za nalorakk mangle on tank"] = &RaidZaTriggerContext::nalorakk_mangle;
        creators["za janalai fire bombs"] = &RaidZaTriggerContext::janalai_bombs;
        creators["za janalai flame breath"] = &RaidZaTriggerContext::janalai_breath;
        creators["za halazzi totem"] = &RaidZaTriggerContext::halazzi_totem;
        creators["za zuljin creeping paralysis"] = &RaidZaTriggerContext::zuljin_paralysis;
        creators["za zuljin energy storm"] = &RaidZaTriggerContext::zuljin_storm;
        creators["za zuljin claw rage"] = &RaidZaTriggerContext::zuljin_claw_rage;
        creators["za zuljin flame pillars"] = &RaidZaTriggerContext::zuljin_pillars;
    }

private:
    static Trigger* akilzon_storm(PlayerbotAI* ai) { return new ZaAkilzonElectricalStormTrigger(ai); }
    static Trigger* static_disruption(PlayerbotAI* ai) { return new ZaStaticDisruptionTrigger(ai); }
    static Trigger* nalorakk_mangle(PlayerbotAI* ai) { return new ZaNalorakkMangleOnTankTrigger(ai); }
    static Trigger* janalai_bombs(PlayerbotAI* ai) { return new ZaJanalaiFireBombsTrigger(ai); }
    static Trigger* janalai_breath(PlayerbotAI* ai) { return new ZaJanalaiFlameBreathTrigger(ai); }
    static Trigger* halazzi_totem(PlayerbotAI* ai) { return new ZaHalazziTotemTrigger(ai); }
    static Trigger* zuljin_paralysis(PlayerbotAI* ai) { return new ZaZuljinCreepingParalysisTrigger(ai); }
    static Trigger* zuljin_storm(PlayerbotAI* ai) { return new ZaZuljinEnergyStormTrigger(ai); }
    static Trigger* zuljin_claw_rage(PlayerbotAI* ai) { return new ZaZuljinClawRageTrigger(ai); }
    static Trigger* zuljin_pillars(PlayerbotAI* ai) { return new ZaZuljinFlamePillarsTrigger(ai); }
};

#endif


