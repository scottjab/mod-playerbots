#include "RaidTkStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidTkStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Kael'thas: Gravity Lapse (35941) -> stop casting and move
    triggers.push_back(new TriggerNode("tk kael gravity lapse",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 6), new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));

    // Kael'thas: Flame Strike (36735 aura telegraph) -> avoid ground
    triggers.push_back(new TriggerNode("tk kael flame strike",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));

    // Void Reaver: Pounding -> stop casting, use defensive
    triggers.push_back(new TriggerNode("tk vr pounding",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 5), nullptr)));

    // Void Reaver: Arcane Orb -> avoid aoe
    triggers.push_back(new TriggerNode("tk vr arcane orb",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Solarian: Wrath of the Astromancer -> move out from players
    triggers.push_back(new TriggerNode("tk solarian wrath",
        NextAction::array(0, new NextAction("move from group", ACTION_RAID + 4), nullptr)));

    // Solarian: Blinding Light -> stop casting
    triggers.push_back(new TriggerNode("tk solarian blinding light",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 5), nullptr)));

    // Kael: Mind Control on bot -> do not attack allies; drop target
    triggers.push_back(new TriggerNode("tk kael mind control",
        NextAction::array(0, new NextAction("stop attack", ACTION_EMERGENCY + 7), nullptr)));

    // Kael: Phoenix -> avoid aoe around phoenix
    triggers.push_back(new TriggerNode("tk kael phoenix",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));
}

void RaidTkStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


