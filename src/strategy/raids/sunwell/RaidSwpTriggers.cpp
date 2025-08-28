#include "RaidSwpTriggers.h"

#include "PlayerbotAI.h"
#include "Playerbots.h"

// Darkness aura 46605 cast results in 45657 damage on expire; check aura on boss
bool SwpKjDarknessTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "kil'jaeden"))
        return boss->HasAura(46605);
    return false;
}

// Armageddon periodic (45921) places ground effect; bot may have visual 45911 nearby, avoid area
bool SwpKjArmageddonTrigger::IsActive()
{
    return bot->HasAura(45911);
}


