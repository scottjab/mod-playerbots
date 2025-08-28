#ifndef _PLAYERBOT_RAIDHYJALTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDHYJALTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidHyjalTriggers.h"

class RaidHyjalTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidHyjalTriggerContext()
    {
        creators["hyjal archimonde doomfire"] = &RaidHyjalTriggerContext::doomfire;
        creators["hyjal archimonde air burst"] = &RaidHyjalTriggerContext::air_burst;
        creators["hyjal winterchill death and decay"] = &RaidHyjalTriggerContext::winterchill_dnd;
        creators["hyjal winterchill icebolt"] = &RaidHyjalTriggerContext::winterchill_icebolt;
        creators["hyjal anetheron carrion swarm"] = &RaidHyjalTriggerContext::anetheron_carrion;
        creators["hyjal kazrogal mark"] = &RaidHyjalTriggerContext::kazrogal_mark;
        creators["hyjal azgalor doom"] = &RaidHyjalTriggerContext::azgalor_doom;
    }

private:
    static Trigger* doomfire(PlayerbotAI* ai) { return new HyjalArchimondeDoomfireTrigger(ai); }
    static Trigger* air_burst(PlayerbotAI* ai) { return new HyjalArchimondeAirBurstTrigger(ai); }
    static Trigger* winterchill_dnd(PlayerbotAI* ai) { return new HyjalWinterchillDeathAndDecayTrigger(ai); }
    static Trigger* winterchill_icebolt(PlayerbotAI* ai) { return new HyjalWinterchillIceboltTrigger(ai); }
    static Trigger* anetheron_carrion(PlayerbotAI* ai) { return new HyjalAnetheronCarrionSwarmTrigger(ai); }
    static Trigger* kazrogal_mark(PlayerbotAI* ai) { return new HyjalKazrogalMarkTrigger(ai); }
    static Trigger* azgalor_doom(PlayerbotAI* ai) { return new HyjalAzgalorDoomTrigger(ai); }
};

#endif


