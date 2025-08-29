#include "RaidHyjalTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Doomfire aura 31945 checks on bot
bool HyjalArchimondeDoomfireTrigger::IsActive()
{
    if (bot->HasAura(31945))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Hyjal] Doomfire on {}", bot->GetName());
        return true;
    }
    return false;
}

// Air Burst cast 32014 on Archimonde
bool HyjalArchimondeAirBurstTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "archimonde"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 32014)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Hyjal] Archimonde casting Air Burst");
                return true;
            }
    }
    return false;
}

// Rage Winterchill: Death and Decay 31258 on boss
bool HyjalWinterchillDeathAndDecayTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "rage winterchill"))
    {
        if (boss->HasAura(31258))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Hyjal] Winterchill Death and Decay active");
            return true;
        }
    }
    return false;
}

// Rage Winterchill: Icebolt 31249 (cast) -> stop casting and defensive
bool HyjalWinterchillIceboltTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "rage winterchill"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 31249)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Hyjal] Winterchill casting Icebolt");
                return true;
            }
    return false;
}

// Anetheron: Carrion Swarm 31306 aura on bot
bool HyjalAnetheronCarrionSwarmTrigger::IsActive()
{
    if (bot->HasAura(31306))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Hyjal] Carrion Swarm on {}", bot->GetName());
        return true;
    }
    return false;
}

// Kaz'rogal: Mark 31447 aura on bot (mana drain) -> prepare defensives
bool HyjalKazrogalMarkTrigger::IsActive()
{
    if (bot->HasAura(31447))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Hyjal] Kaz'rogal Mark on {}", bot->GetName());
        return true;
    }
    return false;
}

// Azgalor: Doom 31347 on bot
bool HyjalAzgalorDoomTrigger::IsActive()
{
    if (bot->HasAura(31347))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Hyjal] Doom on {}", bot->GetName());
        return true;
    }
    return false;
}


