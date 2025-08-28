#include "RaidSscTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Morogrim Tidewalker Earthquake spell 37764
bool SscMorogrimEarthquakeTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "morogrim"))
    {
        if (Spell* spell = boss->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            return spell->m_spellInfo && spell->m_spellInfo->Id == 37764;
    }
    return false;
}

// Hydross Mark stacks (any of 38215..38218..40584 or 38219..38222..40583) on bot
bool SscHydrossMarkTrigger::IsActive()
{
    static const uint32 hydrossMarks[] = { 38215, 38216, 38217, 38218, 38231, 40584, 38219, 38220, 38221, 38222, 38230, 40583 };
    for (uint32 id : hydrossMarks)
        if (bot->HasAura(id))
            return true;
    return false;
}

// Lurker Spout periodic auras 37429 / 37430 active on boss
bool SscLurkerSpoutTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "lurker below"))
        return boss->HasAura(37429) || boss->HasAura(37430);
    return false;
}

// Leotheras Whirlwind 37640 on boss
bool SscLeotherasWhirlwindTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "leotheras"))
        return boss->HasAura(37640);
    return false;
}

// Karathress: Caribdis (21964) casting heal/cyclone (generic, check any current spell)
bool SscKarathressCaribdisCastTrigger::IsActive()
{
    if (Unit* caribdis = AI_VALUE2(Unit*, "find target", "caribdis"))
        return caribdis->IsNonMeleeSpellCast(false);
    return false;
}

// Karathress totems nearby
bool SscKarathressTotemSpawnedTrigger::IsActive()
{
    static const std::vector<std::string> totems = { "22091", "22486", "22487" };
    for (auto const& entry : totems)
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", entry);
        for (ObjectGuid guid : npcs)
            if (Unit* u = botAI->GetUnit(guid))
                if (u->IsAlive())
                    return true;
    }
    return false;
}

// Vashj: Add phase when boss has Magic Barrier (38112) removed and adds are present (simplified: check nearby adds)
bool SscVashjAddPhaseTrigger::IsActive()
{
    if (Unit* vashj = AI_VALUE2(Unit*, "find target", "lady vashj"))
    {
        GuidVector npcs = AI_VALUE2(GuidVector, "nearest npcs", "22055");
        if (!npcs.empty()) return true;
        npcs = AI_VALUE2(GuidVector, "nearest npcs", "22056");
        if (!npcs.empty()) return true;
    }
    return false;
}


