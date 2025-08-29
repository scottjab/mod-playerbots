#include "RaidGruulTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Ground Slam cast: 33525 on Gruul
bool GruulGroundSlamTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "gruul"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo && spell->m_spellInfo->Id == 33525)
            {
                if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                    LOG_INFO("playerbots", "[Raid][Gruul] Ground Slam casting");
                return true;
            }
    }
    return false;
}

// Shatter aura/cast on Gruul or on players: 33654 (cast) / 33671 (effect)
bool GruulShatterTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "gruul"))
        if (boss->HasAura(33654))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Gruul] Shatter incoming");
            return true;
        }

    if (bot->HasAura(33671))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Gruul] Shatter debuff on {}", bot->GetName());
        return true;
    }

    return false;
}


