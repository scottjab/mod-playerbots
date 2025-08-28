#include "RaidHyjalTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Doomfire aura 31945 checks on bot
bool HyjalArchimondeDoomfireTrigger::IsActive()
{
    return bot->HasAura(31945);
}

// Air Burst cast 32014 on Archimonde
bool HyjalArchimondeAirBurstTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "archimonde"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 32014;
    }
    return false;
}

// Rage Winterchill: Death and Decay 31258 on boss
bool HyjalWinterchillDeathAndDecayTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "rage winterchill"))
        return boss->HasAura(31258);
    return false;
}

// Rage Winterchill: Icebolt 31249 (cast) -> stop casting and defensive
bool HyjalWinterchillIceboltTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "rage winterchill"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 31249;
    return false;
}

// Anetheron: Carrion Swarm 31306 aura on bot
bool HyjalAnetheronCarrionSwarmTrigger::IsActive()
{
    return bot->HasAura(31306);
}

// Kaz'rogal: Mark 31447 aura on bot (mana drain) -> prepare defensives
bool HyjalKazrogalMarkTrigger::IsActive()
{
    return bot->HasAura(31447);
}

// Azgalor: Doom 31347 on bot
bool HyjalAzgalorDoomTrigger::IsActive()
{
    return bot->HasAura(31347);
}


