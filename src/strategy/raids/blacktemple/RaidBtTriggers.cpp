#include "RaidBtTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Illidan Flame Crash aura 40832 ground hazard often on bot
bool BtIllidanFlameCrashTrigger::IsActive()
{
    return bot->HasAura(40832);
}

// Illidan Eye Blast casting 39908 on DB target path
bool BtIllidanEyeBlastTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "illidan"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 39908;
    }
    return false;
}

// Naj'entus: Tidal Shield 39872 on boss
bool BtNajentusTidalShieldTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "naj'entus"))
        return boss->HasAura(39872);
    return false;
}

// Supremus: Volcanic Eruption 40276/42055 around; treat as aoe
bool BtSupremusVolcanoTrigger::IsActive()
{
    return bot->HasAura(42055) || bot->HasAura(40276);
}

// Teron Gorefiend: Shadow of Death 40251 on player
bool BtGorefiendShadowOfDeathTrigger::IsActive()
{
    return bot->HasAura(40251);
}

// Gurtogg Bloodboil: Fel Rage self 40594 or target 40604
bool BtBloodboilFelRageTrigger::IsActive()
{
    return bot->HasAura(40604) || bot->HasAura(40594);
}

// Mother Shahraz: Fatal Attraction aura 41001 on player
bool BtShahrazFatalAttractionTrigger::IsActive()
{
    return bot->HasAura(41001);
}

// Illidari Council: Reflective Shield 41475 on priest
bool BtCouncilReflectiveShieldTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "lady malande"))
        return boss->HasAura(41475);
    return false;
}

// Illidari Council: Ground AOE (Flamestrike 41481, Blizzard 41482, Consecration 41541)
bool BtCouncilGroundAoeTrigger::IsActive()
{
    if (Unit* mage = AI_VALUE2(Unit*, "find target", "zerevor"))
        if (mage->HasAura(41481) || mage->HasAura(41482))
            return true;
    if (Unit* pal = AI_VALUE2(Unit*, "find target", "gathios"))
        if (pal->HasAura(41541))
            return true;
    return false;
}

// Illidan: Agonizing Flames 40932 on boss -> avoid aoe
bool BtIllidanAgonizingFlamesTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "illidan"))
        return boss->HasAura(40932);
    return false;
}


