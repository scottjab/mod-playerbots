#include "RaidGruulTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Ground Slam cast: 33525 on Gruul
bool GruulGroundSlamTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "gruul"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 33525;
    }
    return false;
}

// Shatter aura/cast on Gruul or on players: 33654 (cast) / 33671 (effect)
bool GruulShatterTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "gruul"))
        if (boss->HasAura(33654))
            return true;

    if (bot->HasAura(33671))
        return true;

    return false;
}


