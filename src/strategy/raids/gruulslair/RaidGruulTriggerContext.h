#ifndef _PLAYERBOT_RAIDGRUULTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDGRUULTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidGruulTriggers.h"

class RaidGruulTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidGruulTriggerContext()
    {
        creators["gruul ground slam"] = &RaidGruulTriggerContext::ground_slam;
        creators["gruul shatter"] = &RaidGruulTriggerContext::shatter;
    }

private:
    static Trigger* ground_slam(PlayerbotAI* ai) { return new GruulGroundSlamTrigger(ai); }
    static Trigger* shatter(PlayerbotAI* ai) { return new GruulShatterTrigger(ai); }
};

#endif


