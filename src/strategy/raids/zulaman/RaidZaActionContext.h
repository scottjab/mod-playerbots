#ifndef _PLAYERBOT_RAIDZAACTIONS_CONTEXT_H
#define _PLAYERBOT_RAIDZAACTIONS_CONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidZaActions.h"

class RaidZaActionContext : public NamedObjectContext<Action>
{
public:
    RaidZaActionContext()
    {
        creators["za move to storm eye"] = &RaidZaActionContext::move_to_storm_eye;
        creators["za spread for storm"] = &RaidZaActionContext::spread_for_storm;
        creators["za kill halazzi totem"] = &RaidZaActionContext::kill_halazzi_totem;
        creators["za swap to bear side"] = &RaidZaActionContext::swap_to_bear_side;
    }

private:
    static Action* move_to_storm_eye(PlayerbotAI* ai) { return new RaidZaMoveToStormEyeAction(ai); }
    static Action* spread_for_storm(PlayerbotAI* ai) { return new RaidZaSpreadForStormAction(ai); }
    static Action* kill_halazzi_totem(PlayerbotAI* ai) { return new RaidZaKillHalazziTotemAction(ai); }
    static Action* swap_to_bear_side(PlayerbotAI* ai) { return new RaidZaSwapToBearSideAction(ai); }
};

#endif


