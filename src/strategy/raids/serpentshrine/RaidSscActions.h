#ifndef _PLAYERBOT_RAIDSSCACTIONS_H
#define _PLAYERBOT_RAIDSSCACTIONS_H

#include "Action.h"
#include "MovementActions.h"
#include "AttackAction.h"

class RaidSscAttackVashjAddAction : public AttackAction
{
public:
    RaidSscAttackVashjAddAction(PlayerbotAI* ai) : AttackAction(ai, "ssc attack vashj add") {}
    bool Execute(Event event) override;
};

class RaidSscRearFlankLurkerAction : public MovementAction
{
public:
    RaidSscRearFlankLurkerAction(PlayerbotAI* ai) : MovementAction(ai, "ssc lurker rear flank") {}
    bool Execute(Event event) override;
};

class RaidSscInterruptCaribdisAction : public Action
{
public:
    RaidSscInterruptCaribdisAction(PlayerbotAI* ai) : Action(ai, "ssc interrupt caribdis") {}
    bool Execute(Event event) override;
};

class RaidSscAttackKarathressTotemAction : public AttackAction
{
public:
    RaidSscAttackKarathressTotemAction(PlayerbotAI* ai) : AttackAction(ai, "ssc attack karathress totem") {}
    bool Execute(Event event) override;
};

class RaidSscAttackKarathressTargetAction : public AttackAction
{
public:
    RaidSscAttackKarathressTargetAction(PlayerbotAI* ai) : AttackAction(ai, "ssc attack karathress target") {}
    bool Execute(Event event) override;
};

#endif


