#ifndef _PLAYERBOT_RAIDKARAACTIONCONTEXT_H
#define _PLAYERBOT_RAIDKARAACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidKaraActions.h"
#include "PlayerbotAI.h"

class RaidKaraActionContext : public NamedObjectContext<Action>
{
public:
    RaidKaraActionContext()
    {
        creators["kara stay behind boss"] = &RaidKaraActionContext::stay_behind_boss;
        creators["kara curator evocate"] = &RaidKaraActionContext::curator_evocate;
        creators["kara aran avoid aoe"] = &RaidKaraActionContext::aran_avoid_aoe;
        creators["kara malchezaar avoid infernal"] = &RaidKaraActionContext::malchezaar_avoid_infernal;
    }

private:
    static Action* stay_behind_boss(PlayerbotAI* ai) { return new KaraStayBehindBossAction(ai); }
    static Action* curator_evocate(PlayerbotAI* ai) { return new KaraCuratorEvocateAction(ai); }
    static Action* aran_avoid_aoe(PlayerbotAI* ai) { return new KaraAranAvoidAoeAction(ai); }
    static Action* malchezaar_avoid_infernal(PlayerbotAI* ai) { return new KaraMalchezaarAvoidInfernalAction(ai); }
};

#endif


