#ifndef _PLAYERBOT_RAIDMAGTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDMAGTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "RaidMagTriggers.h"

class RaidMagTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidMagTriggerContext()
    {
        creators["mag quake"] = &RaidMagTriggerContext::quake;
        creators["mag blast nova"] = &RaidMagTriggerContext::blast_nova;
        creators["mag debris"] = &RaidMagTriggerContext::debris;
    }

private:
    static Trigger* quake(PlayerbotAI* ai) { return new MagQuakeTrigger(ai); }
    static Trigger* blast_nova(PlayerbotAI* ai) { return new MagBlastNovaTrigger(ai); }
    static Trigger* debris(PlayerbotAI* ai) { return new MagDebrisTrigger(ai); }
};

#endif


