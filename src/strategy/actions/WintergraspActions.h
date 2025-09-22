/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license
 */

#ifndef _PLAYERBOT_WINTERGRASPACTIONS_H
#define _PLAYERBOT_WINTERGRASPACTIONS_H

#include "Action.h"
#include "MovementActions.h"

// Auto-accept packet-driven invites

class WgAcceptQueueInviteAction : public Action
{
public:
    WgAcceptQueueInviteAction(PlayerbotAI* botAI) : Action(botAI, "wg queue invite") {}
    bool Execute(Event event) override;
};

class WgAcceptEntryInviteAction : public Action
{
public:
    WgAcceptEntryInviteAction(PlayerbotAI* botAI) : Action(botAI, "wg entry invite") {}
    bool Execute(Event event) override;
};

// Periodic safety: ensure bot is queued/joins WG when in zone
class WgEnsureQueuedAction : public Action
{
public:
    WgEnsureQueuedAction(PlayerbotAI* botAI) : Action(botAI, "wg ensure queued") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

// Choose an objective spot (attacker: approach walls/workshops; defender: towers/keep)
class WgSelectObjectiveAction : public Action
{
public:
    WgSelectObjectiveAction(PlayerbotAI* botAI) : Action(botAI, "wg select objective") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

// Move towards the selected objective
class WgMoveToObjectiveAction : public MovementAction
{
public:
    WgMoveToObjectiveAction(PlayerbotAI* botAI) : MovementAction(botAI, "wg move to objective") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif


