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

    // Karathress: Sear Nova -> avoid aoe (especially melee)
    triggers.push_back(new TriggerNode("ssc karathress sear nova",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), new NextAction("stop non melee", ACTION_EMERGENCY + 4), nullptr)));

    // Karathress: Power-of-* -> use defensives
    triggers.push_back(new TriggerNode("ssc karathress power",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 2), nullptr)));

    // Karathress: Blessing of the Tides -> purge/cleanse priority
    triggers.push_back(new TriggerNode("ssc karathress blessing",
        NextAction::array(0, new NextAction("purge", ACTION_DISPEL + 2), nullptr)));

    // Karathress: Cataclysmic Bolt -> defensives and healer attention
    triggers.push_back(new TriggerNode("ssc karathress cataclysmic bolt",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 3), new NextAction("healing potion", ACTION_EMERGENCY + 2), nullptr)));

    // Caribdis: Cyclone nearby – move out
    triggers.push_back(new TriggerNode("ssc caribdis cyclone",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Caribdis: Tidal Surge – stop casting to prevent lockouts
    triggers.push_back(new TriggerNode("ssc caribdis tidal surge",
        NextAction::array(0, new NextAction("stop non melee", ACTION_EMERGENCY + 5), nullptr)));

    // Sharkkis: Bestial Wrath/The Beast Within – use dispels/tranq
    triggers.push_back(new TriggerNode("ssc sharkkis enrage",
        NextAction::array(0, new NextAction("tranquilizing shot", ACTION_DISPEL + 3), new NextAction("purge", ACTION_DISPEL + 2), nullptr)));

    // Karathress: general encounter active -> follow fight plan (handled by core actions/targeting)
    triggers.push_back(new TriggerNode("ssc karathress encounter",
        NextAction::array(0, new NextAction("ssc attack karathress target", ACTION_HIGH + 3), nullptr)));

    // Vashj add phase: focus adds
    triggers.push_back(new TriggerNode("ssc vashj add phase",
        NextAction::array(0, new NextAction("ssc attack vashj add", ACTION_RAID + 4), nullptr)));

    // Vashj: Static Charge – spread/avoid
    triggers.push_back(new TriggerNode("ssc vashj static charge",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Vashj: Entangle – use trinket/stop casting
    triggers.push_back(new TriggerNode("ssc vashj entangle",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 3), new NextAction("stop non melee", ACTION_EMERGENCY + 2), nullptr)));

    // Vashj: Shock Blast – avoid melee range during cast
    triggers.push_back(new TriggerNode("ssc vashj shock blast",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), new NextAction("stop non melee", ACTION_EMERGENCY + 3), nullptr)));

    // Vashj: Toxic Spores – avoid ground clouds
    triggers.push_back(new TriggerNode("ssc vashj toxic spores",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_MOVE + 5), nullptr)));

    // Vashj: Phase 3 – use cooldowns
    triggers.push_back(new TriggerNode("ssc vashj phase3",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 2), nullptr)));
}

void RaidSscStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


