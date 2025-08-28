#include "RaidSscStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidSscStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Morogrim Tidewalker: Earthquake (37764) -> stop casting and avoid
    triggers.push_back(new TriggerNode("ssc morogrim earthquake",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 5), new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Lady Vashj: Strider/Elite spawns are handled by generic AoE avoidance and focus-fire

    // Hydross: marks stack awareness -> move across the line (handled by master), prioritize survival
    triggers.push_back(new TriggerNode("ssc hydross mark",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 1), nullptr)));

    // Lurker: spout -> flank
    triggers.push_back(new TriggerNode("ssc lurker spout",
        NextAction::array(0, new NextAction("ssc lurker rear flank", ACTION_EMERGENCY + 4), nullptr)));

    // Leotheras: whirlwind -> avoid aoe
    triggers.push_back(new TriggerNode("ssc leotheras whirlwind",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Karathress: Caribdis casts -> interrupt
    triggers.push_back(new TriggerNode("ssc karathress caribdis cast",
        NextAction::array(0, new NextAction("ssc interrupt caribdis", ACTION_INTERRUPT + 6), nullptr)));

    // Karathress: Totems -> hard focus
    triggers.push_back(new TriggerNode("ssc karathress totem",
        NextAction::array(0, new NextAction("ssc attack karathress totem", ACTION_EMERGENCY + 7), nullptr)));

    // Vashj add phase: focus adds
    triggers.push_back(new TriggerNode("ssc vashj add phase",
        NextAction::array(0, new NextAction("ssc attack vashj add", ACTION_RAID + 4), nullptr)));
}

void RaidSscStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


