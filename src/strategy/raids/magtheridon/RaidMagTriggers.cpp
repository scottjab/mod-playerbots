#include "RaidMagTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Quake 30657 cast by Magtheridon
bool MagQuakeTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "magtheridon"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 30657)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Magtheridon] Quake casting");
                return true;
            }
    }
    return false;
}

// Blast Nova 30616 cast by Magtheridon
bool MagBlastNovaTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "magtheridon"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 30616)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Magtheridon] Blast Nova casting");
                return true;
            }
    }
    return false;
}

// Debris visual/damage 30632/30631 around area
bool MagDebrisTrigger::IsActive()
{
    if (bot->HasAura(30632))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Magtheridon] Debris near {}", bot->GetName());
        return true;
    }
    return false;
}


