#ifndef _PLAYERBOT_RAIDSSCACTIONCONTEXT_H
#define _PLAYERBOT_RAIDSSCACTIONCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidSscActions.h"

class RaidSscActionContext : public NamedObjectContext<Action>
{
public:
    RaidSscActionContext()
    {
        creators["ssc attack vashj add"] = &RaidSscActionContext::vashj_add;
        creators["ssc lurker rear flank"] = &RaidSscActionContext::lurker_flank;
        creators["ssc interrupt caribdis"] = &RaidSscActionContext::caribdis_interrupt;
        creators["ssc attack karathress totem"] = &RaidSscActionContext::karathress_totem;
    }

private:
    static Action* vashj_add(PlayerbotAI* ai) { return new RaidSscAttackVashjAddAction(ai); }
    static Action* lurker_flank(PlayerbotAI* ai) { return new RaidSscRearFlankLurkerAction(ai); }
    static Action* caribdis_interrupt(PlayerbotAI* ai) { return new RaidSscInterruptCaribdisAction(ai); }
    static Action* karathress_totem(PlayerbotAI* ai) { return new RaidSscAttackKarathressTotemAction(ai); }
};

#endif


