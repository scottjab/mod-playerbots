#include "RaidTkTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Kael'thas Gravity Lapse 35941
bool TkKaelGravityLapseTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kael'thas"))
    {
        if (boss->HasAura(35941))
            return true;
    }
    return false;
}

// Kael'thas Flame Strike ground telegraph aura on trigger NPC: 36735 (aura), 36731 (damage)
bool TkKaelFlameStrikeTrigger::IsActive()
{
    if (bot->HasAura(36735))
        return true;
    return false;
}

// Void Reaver Pounding 34162 on boss
bool TkVrPoundingTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "void reaver"))
        return boss->HasAura(34162);
    return false;
}

// Void Reaver Arcane Orb 34172 is casting; treat as aoe to avoid
bool TkVrArcaneOrbTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "void reaver"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 34172;
    return false;
}

// Solarian Wrath of the Astromancer 42783 on player
bool TkSolarianWrathTrigger::IsActive()
{
    return bot->HasAura(42783);
}

// Solarian Blinding Light 33009 on boss (cast) -> avoid/stop
bool TkSolarianBlindingLightTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "solarian"))
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 33009;
    return false;
}

// Kael Mind Control 36797 aura on players
bool TkKaelMindControlTrigger::IsActive()
{
    return bot->HasAura(36797);
}

// Kael Phoenix summon 36723 on boss -> avoid phoenixes (generic aoe)
bool TkKaelPhoenixTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kael'thas"))
        return boss->HasAura(36723);
    return false;
}


