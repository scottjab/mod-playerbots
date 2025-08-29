#include "RaidKaraTriggers.h"
#include "Playerbots.h"

KaraCuratorEvocateTrigger::KaraCuratorEvocateTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kara curator evocate") {}
bool KaraCuratorEvocateTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "the curator");
    if (!boss)
        return false;
    // Simple: trigger if curator exists (placeholder for Evocation check)
    if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
        LOG_INFO("playerbots", "[Raid][Karazhan] Curator phase event (Evocation placeholder)");
    return true;
}

KaraAranAoeTrigger::KaraAranAoeTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kara aran aoe") {}
bool KaraAranAoeTrigger::IsActive()
{
    // Placeholder: act when Shade of Aran is around
    if (AI_VALUE2(Unit*, "find target", "shade of aran"))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Karazhan] Shade of Aran nearby (AOE awareness)");
        return true;
    }
    return false;
}

KaraMalchezaarInfernalTrigger::KaraMalchezaarInfernalTrigger(PlayerbotAI* botAI)
    : Trigger(botAI, "kara malchezaar infernal") {}
bool KaraMalchezaarInfernalTrigger::IsActive()
{
    if (AI_VALUE2(Unit*, "find target", "infernal"))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Karazhan] Infernal active (Prince Malchezaar)");
        return true;
    }
    return false;
}


