#ifndef _PLAYERBOT_RAIDZAACTIONS_H
#define _PLAYERBOT_RAIDZAACTIONS_H

#include "Action.h"
#include "MovementActions.h"
#include "AttackAction.h"

class RaidZaMoveToStormEyeAction : public MovementAction
{
public:
    RaidZaMoveToStormEyeAction(PlayerbotAI* botAI) : MovementAction(botAI, "za move to storm eye") {}
    bool Execute(Event event) override;
};

class RaidZaSpreadForStormAction : public MovementAction
{
public:
    RaidZaSpreadForStormAction(PlayerbotAI* botAI) : MovementAction(botAI, "za spread for storm") {}
    bool Execute(Event event) override;
};

class RaidZaKillHalazziTotemAction : public AttackAction
{
public:
    RaidZaKillHalazziTotemAction(PlayerbotAI* botAI) : AttackAction(botAI, "za kill halazzi totem") {}
    bool Execute(Event event) override;
};

class RaidZaSwapToBearSideAction : public MovementAction
{
public:
    RaidZaSwapToBearSideAction(PlayerbotAI* botAI) : MovementAction(botAI, "za swap to bear side") {}
    bool Execute(Event event) override;
};

#endif


