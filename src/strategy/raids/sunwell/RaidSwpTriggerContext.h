#ifndef _PLAYERBOT_RAIDSWPTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDSWPTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidSwpTriggers.h"

class RaidSwpTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidSwpTriggerContext()
    {
        creators["swp kj darkness"] = &RaidSwpTriggerContext::darkness;
        creators["swp kj armageddon"] = &RaidSwpTriggerContext::armageddon;
    }

private:
    static Trigger* darkness(PlayerbotAI* ai) { return new SwpKjDarknessTrigger(ai); }
    static Trigger* armageddon(PlayerbotAI* ai) { return new SwpKjArmageddonTrigger(ai); }
};

#endif


