#ifndef _PLAYERBOT_RAIDKARATRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDKARATRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidKaraTriggers.h"

class RaidKaraTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidKaraTriggerContext()
    {
        creators["kara curator evocate"] = &RaidKaraTriggerContext::curator_evocate;
        creators["kara aran aoe"] = &RaidKaraTriggerContext::aran_aoe;
        creators["kara malchezaar infernal"] = &RaidKaraTriggerContext::malchezaar_infernal;
    }

private:
    static Trigger* curator_evocate(PlayerbotAI* ai) { return new KaraCuratorEvocateTrigger(ai); }
    static Trigger* aran_aoe(PlayerbotAI* ai) { return new KaraAranAoeTrigger(ai); }
    static Trigger* malchezaar_infernal(PlayerbotAI* ai) { return new KaraMalchezaarInfernalTrigger(ai); }
};

#endif


