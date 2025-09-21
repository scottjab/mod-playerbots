#include "RaidZaActions.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Player.h"

// Move into the storm safe eye on Akil'zon: target has dynobject 44007; fallback to boss target position
bool RaidZaMoveToStormEyeAction::Execute(Event /*event*/)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "akil'zon");
    if (!boss)
        return false;

    // Try to move near the boss's current target (safe eye often around lifted player)
    Unit* stormTarget = nullptr;
    GuidVector friends = AI_VALUE(GuidVector, "nearest friendly players");
    for (ObjectGuid guid : friends)
    {
        Unit* u = botAI->GetUnit(guid);
        if (!u)
            continue;
        if (u->GetDynObject(44007))
        {
            stormTarget = u;
            break;
        }
    }
    if (!stormTarget)
        stormTarget = boss;

    return MoveNear(stormTarget, 3.0f);
}

// Spread during Energy Storm and similar; keep 8y from nearest ally
bool RaidZaSpreadForStormAction::Execute(Event /*event*/)
{
    GuidVector friends = AI_VALUE(GuidVector, "nearest friendly players");
    for (ObjectGuid guid : friends)
    {
        Unit* u = botAI->GetUnit(guid);
        if (!u || u == bot)
            continue;
        if (bot->GetDistance(u) < 8.0f)
            return MoveFromGroup(8.0f);
    }
    return false;
}

// Focus and attack Halazzi's totem (entry 24224)
bool RaidZaKillHalazziTotemAction::Execute(Event /*event*/)
{
    GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", "24224");
    for (ObjectGuid guid : npcs)
        if (Unit* u = botAI->GetUnit(guid))
            if (u->IsAlive() && u->GetEntry() == 24224)
                return Attack(u);
    return false;
}

// Move to bear's side (Nalorakk form awareness): just perform rear flank to avoid frontal cones
bool RaidZaSwapToBearSideAction::Execute(Event /*event*/)
{
    // Prefer a side flank over strict rear to avoid pathing failures in tight spaces
    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target)
        return false;

    // If already not in front and not in rear danger, do nothing
    // Use the same angles as RearFlankAction for consistency
    const float minAngle = ANGLE_90_DEG;
    const float maxAngle = ANGLE_120_DEG;
    bool inFront = target->HasInArc(2.f * minAngle, bot);
    bool inRear = !target->HasInArc((2.f * M_PI) - maxAngle, bot);
    if (!inFront && !inRear)
        return false;

    // Move to pure side: ±90° at melee range
    float baseDistance = bot->GetMeleeRange(target) * 0.6f;
    Position left = target->GetPosition();
    Position right = target->GetPosition();
    left.RelocatePolarOffset(ANGLE_90_DEG, baseDistance);
    right.RelocatePolarOffset(-ANGLE_90_DEG, baseDistance);
    Position* dest = (bot->GetExactDist2d(left) < bot->GetExactDist2d(right)) ? &left : &right;
    return MoveTo(bot->GetMapId(), dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false, false, false, true, MovementPriority::MOVEMENT_COMBAT);
}

bool RaidZaSwapToBearSideAction::isUseful()
{
    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target)
        return false;
    // Tanks maintain boss positioning; ranged shouldn't try to side-flank
    if (botAI->IsTank(bot) || !botAI->IsMelee(bot))
        return false;
    return true;
}


bool RaidZaStackOnMasterDuringBombsAction::Execute(Event /*event*/)
{
    Player* master = botAI->GetMaster();
    if (!master || !master->IsAlive())
        return false;

    // Tanks should not stack by this action
    if (botAI->IsTank(bot))
        return false;

    // Move to within melee range of master (stand on the player)
    return MoveNear(master, 1.5f);
}

bool RaidZaStackOnMasterDuringBombsAction::isUseful()
{
    // Tanks do not stack; they maintain positioning
    if (botAI->IsTank(bot))
        return false;

    // Only during Jan'alai fire bombs
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "jan'alai"))
    {
        if (boss->HasAura(42621))
            return true;
    }
    return false;
}


