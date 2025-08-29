#include "RaidTkTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Kael'thas Gravity Lapse 35941
bool TkKaelGravityLapseTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kael'thas"))
    {
        if (boss->HasAura(35941))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][The Eye] Kael'thas Gravity Lapse active");
            return true;
        }
    }
    return false;
}

// Kael'thas Flame Strike ground telegraph aura on trigger NPC: 36735 (aura), 36731 (damage)
bool TkKaelFlameStrikeTrigger::IsActive()
{
    if (bot->HasAura(36735))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][The Eye] Flame Strike telegraph on {}", bot->GetName());
        return true;
    }
    return false;
}

// Void Reaver Pounding 34162 on boss
bool TkVrPoundingTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "void reaver"))
    {
        if (boss->HasAura(34162))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][The Eye] Void Reaver Pounding active");
            return true;
        }
    }
    return false;
}

// Void Reaver Arcane Orb 34172 is casting; treat as aoe to avoid
bool TkVrArcaneOrbTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "void reaver"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 34172)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][The Eye] Void Reaver casting Arcane Orb");
                return true;
            }
    return false;
}

// Solarian Wrath of the Astromancer 42783 on player
bool TkSolarianWrathTrigger::IsActive()
{
    if (bot->HasAura(42783))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][The Eye] Wrath of the Astromancer on {}", bot->GetName());
        return true;
    }
    return false;
}

// Solarian Blinding Light 33009 on boss (cast) -> avoid/stop
bool TkSolarianBlindingLightTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "solarian"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 33009)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][The Eye] Solarian casting Blinding Light");
                return true;
            }
    return false;
}

// Kael Mind Control 36797 aura on players
bool TkKaelMindControlTrigger::IsActive()
{
    if (bot->HasAura(36797))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][The Eye] Kael'thas Mind Control on {}", bot->GetName());
        return true;
    }
    return false;
}

// Kael Phoenix summon 36723 on boss -> avoid phoenixes (generic aoe)
bool TkKaelPhoenixTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kael'thas"))
    {
        if (boss->HasAura(36723))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][The Eye] Kael'thas Phoenix summoned");
            return true;
        }
    }
    return false;
}


