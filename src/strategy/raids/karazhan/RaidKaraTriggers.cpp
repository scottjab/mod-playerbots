#include "RaidKaraTriggers.h"
#include "Playerbots.h"

KaraCuratorEvocateTrigger::KaraCuratorEvocateTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kara curator evocate") {}
bool KaraCuratorEvocateTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "the curator");
    if (!boss)
        return false;
    // Simple: trigger if curator exists (placeholder for Evocation check)
    return true;
}

KaraAranAoeTrigger::KaraAranAoeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kara aran aoe") {}
bool KaraAranAoeTrigger::IsActive()
{
    // Placeholder: act when Shade of Aran is around
    return AI_VALUE2(Unit*, "find target", "shade of aran");
}

KaraMalchezaarInfernalTrigger::KaraMalchezaarInfernalTrigger(PlayerbotAI* botAI)
    : Trigger(botAI, "kara malchezaar infernal") {}
bool KaraMalchezaarInfernalTrigger::IsActive()
{
    return AI_VALUE2(Unit*, "find target", "infernal");
}


