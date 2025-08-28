#include "RaidMagTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Quake 30657 cast by Magtheridon
bool MagQuakeTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "magtheridon"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 30657;
    }
    return false;
}

// Blast Nova 30616 cast by Magtheridon
bool MagBlastNovaTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "magtheridon"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 30616;
    }
    return false;
}

// Debris visual/damage 30632/30631 around area
bool MagDebrisTrigger::IsActive()
{
    if (bot->HasAura(30632))
        return true;
    return false;
}


