#include "RaidKaraActions.h"
#include "Playerbots.h"

bool KaraStayBehindBossAction::Execute(Event event)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "boss");
    if (!boss)
        return false;

    // Try to move behind target using existing movement action
    SetBehindTargetAction setBehind(botAI);
    return setBehind.Execute(event);
}

bool KaraCuratorEvocateAction::Execute(Event event)
{
    // Focus adds (Astral Flares) during Evocation; fallback to boss
    Unit* add = AI_VALUE2(Unit*, "find target", "astral flare");
    if (add)
        return Attack(add);

    Unit* boss = AI_VALUE2(Unit*, "find target", "the curator");
    if (boss)
        return Attack(boss);

    return false;
}

bool KaraAranAvoidAoeAction::Execute(Event event)
{
    // Keep moving if taking periodic frost/fire damage (Blizzard/Flames)
    if (bot->GetVictim() && bot->GetGUID() == bot->GetVictim()->GetGUID())
        return false;

    AvoidAoeAction avoid(botAI);
    return avoid.Execute(event);
}

bool KaraMalchezaarAvoidInfernalAction::Execute(Event event)
{
    // Move away if near Infernal targets
    Unit* infernal = AI_VALUE2(Unit*, "find target", "infernal");
    if (!infernal)
        return false;

    return MoveAway(infernal, 20.0f);
}


