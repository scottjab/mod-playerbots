/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license
 */

#ifndef _PLAYERBOT_WINTERGRASPACTIONS_H
#define _PLAYERBOT_WINTERGRASPACTIONS_H

#include "Action.h"

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

#endif


