#include "RaidSwpTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Darkness aura 46605 cast results in 45657 damage on expire; check aura on boss
bool SwpKjDarknessTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kil'jaeden"))
    {
        if (boss->HasAura(46605))
        {
            if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
                LOG_INFO("playerbots", "[Raid][Sunwell] Kil'jaeden Darkness active");
            return true;
        }
    }
    return false;
}

// Armageddon periodic (45921) places ground effect; bot may have visual 45911 nearby, avoid area
bool SwpKjArmageddonTrigger::IsActive()
{
    if (bot->HasAura(45911))
    {
        if (botAI->HasStrategy("debug", BOT_STATE_NON_COMBAT))
            LOG_INFO("playerbots", "[Raid][Sunwell] Armageddon ground visual near {}", bot->GetName());
        return true;
    }
    return false;
}


