#ifndef _PLAYERBOT_RAIDKARAACTIONS_H
#define _PLAYERBOT_RAIDKARAACTIONS_H

#include "Action.h"
#include "MovementActions.h"
#include "AttackAction.h"

// Attumen/Midnight: spread a bit to avoid cleave, stay behind
class KaraStayBehindBossAction : public MovementAction
{
public:
    KaraStayBehindBossAction(PlayerbotAI* botAI) : MovementAction(botAI, "kara stay behind boss") {}
    bool Execute(Event event) override;
};

// Curator: move out of Evocation sparks path and focus adds during Evocate
class KaraCuratorEvocateAction : public AttackAction
{
public:
    KaraCuratorEvocateAction(PlayerbotAI* botAI) : AttackAction(botAI, "kara curator evocate") {}
    bool Execute(Event event) override;
};

// Aran: move out of blizzard/aoe
class KaraAranAvoidAoeAction : public MovementAction
{
public:
    KaraAranAvoidAoeAction(PlayerbotAI* botAI) : MovementAction(botAI, "kara aran avoid aoe") {}
    bool Execute(Event event) override;
};

// Malchezaar: avoid infernals
class KaraMalchezaarAvoidInfernalAction : public MovementAction
{
public:
    KaraMalchezaarAvoidInfernalAction(PlayerbotAI* botAI) : MovementAction(botAI, "kara malchezaar avoid infernal") {}
    bool Execute(Event event) override;
};

#endif


