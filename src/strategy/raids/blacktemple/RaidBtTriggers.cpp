#include "RaidBtTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Illidan Flame Crash aura 40832 ground hazard often on bot
bool BtIllidanFlameCrashTrigger::IsActive()
{
    if (bot->HasAura(40832))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Black Temple] Illidan Flame Crash on {}", bot->GetName());
        return true;
    }
    return false;
}

// Illidan Eye Blast casting 39908 on DB target path
bool BtIllidanEyeBlastTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "illidan"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 39908)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Black Temple] Illidan casting Eye Blast");
                return true;
            }
    }
    return false;
}

// Naj'entus: Tidal Shield 39872 on boss
bool BtNajentusTidalShieldTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "naj'entus"))
    {
        if (boss->HasAura(39872))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Black Temple] Naj'entus Tidal Shield active");
            return true;
        }
    }
    return false;
}

// Supremus: Volcanic Eruption 40276/42055 around; treat as aoe
bool BtSupremusVolcanoTrigger::IsActive()
{
    if (bot->HasAura(42055) || bot->HasAura(40276))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Black Temple] Supremus volcanic ground hazard near {}", bot->GetName());
        return true;
    }
    return false;
}

// Teron Gorefiend: Shadow of Death 40251 on player
bool BtGorefiendShadowOfDeathTrigger::IsActive()
{
    if (bot->HasAura(40251))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Black Temple] Shadow of Death on {}", bot->GetName());
        return true;
    }
    return false;
}

// Gurtogg Bloodboil: Fel Rage self 40594 or target 40604
bool BtBloodboilFelRageTrigger::IsActive()
{
    if (bot->HasAura(40604) || bot->HasAura(40594))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Black Temple] Fel Rage active on {}", bot->GetName());
        return true;
    }
    return false;
}

// Mother Shahraz: Fatal Attraction aura 41001 on player
bool BtShahrazFatalAttractionTrigger::IsActive()
{
    if (bot->HasAura(41001))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Black Temple] Fatal Attraction on {}", bot->GetName());
        return true;
    }
    return false;
}

// Illidari Council: Reflective Shield 41475 on priest
bool BtCouncilReflectiveShieldTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "lady malande"))
    {
        if (boss->HasAura(41475))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Black Temple] Priest Reflective Shield active");
            return true;
        }
    }
    return false;
}

// Illidari Council: Ground AOE (Flamestrike 41481, Blizzard 41482, Consecration 41541)
bool BtCouncilGroundAoeTrigger::IsActive()
{
    if (Unit* mage = AI_VALUE2(Unit*, "find target", "zerevor"))
        if (mage->HasAura(41481) || mage->HasAura(41482))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Black Temple] Zerevor ground AOE active");
            return true;
        }
    if (Unit* pal = AI_VALUE2(Unit*, "find target", "gathios"))
        if (pal->HasAura(41541))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Black Temple] Gathios consecration active");
            return true;
        }
    return false;
}

// Illidan: Agonizing Flames 40932 on boss -> avoid aoe
bool BtIllidanAgonizingFlamesTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "illidan"))
    {
        if (boss->HasAura(40932))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Black Temple] Illidan Agonizing Flames active");
            return true;
        }
    }
    return false;
}


