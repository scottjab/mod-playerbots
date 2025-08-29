#include "RaidZaTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Akil'zon electrical storm safe eye: target player has aura 43648 and dynobject 44007
bool ZaAkilzonElectricalStormTrigger::IsActive()
{
    GuidVector friends = AI_VALUE(GuidVector, "nearest friendly players");
    for (ObjectGuid guid : friends)
    {
        Unit* u = botAI->GetUnit(guid);
        if (!u)
            continue;
        if (u->HasAura(43648))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Electrical Storm target identified");
            return true;
        }
        if (u->GetDynObject(44007))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Electrical Storm eye dynobject detected");
            return true;
        }
    }
    return false;
}

// Static Disruption debuff on player: 43622
bool ZaStaticDisruptionTrigger::IsActive()
{
    if (bot->HasAura(43622))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Zul'Aman] Static Disruption on {}", bot->GetName());
        return true;
    }
    return false;
}

// Nalorakk: Mangle (42389) on current tank -> prompt external cooldowns or awareness; tank detection via role
bool ZaNalorakkMangleOnTankTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "nalorakk"))
    {
        Unit* victim = boss->GetVictim();
        if (!victim)
            return false;
        if (victim->HasAura(42389))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Nalorakk Mangle on tank");
            return botAI->IsTank(bot) || botAI->IsHeal(bot);
        }
    }
    return false;
}

// Jan'alai: Fire Bombs phase, boss channels 42621
bool ZaJanalaiFireBombsTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "jan'alai"))
    {
        if (boss->HasAura(42621))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Jan'alai Fire Bombs channel active");
            return true;
        }
    }
    return false;
}

// Jan'alai: Flame Breath 43140 while casting; we flank
bool ZaJanalaiFlameBreathTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "jan'alai"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 43140)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Zul'Aman] Jan'alai casting Flame Breath");
                return true;
            }
    }
    return false;
}

// Halazzi: Summon Totem 43302 -> totem NPC 24224 present
bool ZaHalazziTotemTrigger::IsActive()
{
    GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", "24224");
    for (ObjectGuid guid : npcs)
        if (Unit* u = botAI->GetUnit(guid))
            if (u->IsAlive())
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Zul'Aman] Halazzi totem present");
                return true;
            }
    return false;
}

// Zul'jin Bear phase: Creeping Paralysis 43095 on players
bool ZaZuljinCreepingParalysisTrigger::IsActive()
{
    if (bot->HasAura(43095))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Zul'Aman] Creeping Paralysis on {}", bot->GetName());
        return true;
    }
    return false;
}

// Zul'jin Eagle phase: Energy Storm 43983 active on boss
bool ZaZuljinEnergyStormTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "zul'jin"))
    {
        if (boss->HasAura(43983))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Energy Storm active");
            return true;
        }
    }
    return false;
}

// Zul'jin Lynx phase: Claw Rage aura 43149 on boss; move away from group if targeted
bool ZaZuljinClawRageTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "zul'jin"))
    {
        if (boss->HasAura(43149))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Claw Rage active");
            return true;
        }
    }
    return false;
}

// Zul'jin Dragonhawk: Flame Whirl 43213 or Pillars 43216 -> avoid aoe
bool ZaZuljinFlamePillarsTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "zul'jin"))
    {
        if (boss->HasAura(43213) || boss->HasAura(43216))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Zul'Aman] Flame Whirl/Pillars active");
            return true;
        }
    }
    return false;
}


