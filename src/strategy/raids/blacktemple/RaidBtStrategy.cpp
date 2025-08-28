#include "RaidBtStrategy.h"
#include "Playerbots.h"
#include "Trigger.h"

void RaidBtStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Illidan Flame Crash (40832) -> avoid ground
    triggers.push_back(new TriggerNode("bt illidan flame crash",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));

    // Illidan Eye Blast path hazard -> avoid aoe when eye beam trigger is active
    triggers.push_back(new TriggerNode("bt illidan eye blast",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));

    // Naj'entus: Tidal Shield -> stop dps; wait for throw (players handle)
    triggers.push_back(new TriggerNode("bt najentus tidal shield",
        NextAction::array(0, new NextAction("stop attack", ACTION_EMERGENCY + 6), nullptr)));

    // Supremus: Volcanoes -> avoid ground
    triggers.push_back(new TriggerNode("bt supremus volcano",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Teron Gorefiend: Shadow of Death on bot -> survival (move away)
    triggers.push_back(new TriggerNode("bt gorefiend shadow of death",
        NextAction::array(0, new NextAction("move from group", ACTION_EMERGENCY + 5), nullptr)));

    // Bloodboil: Fel Rage target -> avoid group, kite
    triggers.push_back(new TriggerNode("bt bloodboil fel rage",
        NextAction::array(0, new NextAction("move from group", ACTION_EMERGENCY + 5), nullptr)));

    // Mother Shahraz: Fatal Attraction -> spread
    triggers.push_back(new TriggerNode("bt shahraz fatal attraction",
        NextAction::array(0, new NextAction("move from group", ACTION_EMERGENCY + 6), nullptr)));

    // Illidari Council: Reflective Shield -> stop attack
    triggers.push_back(new TriggerNode("bt council reflective shield",
        NextAction::array(0, new NextAction("stop attack", ACTION_EMERGENCY + 6), nullptr)));

    // Illidari Council: Ground AOE -> avoid
    triggers.push_back(new TriggerNode("bt council ground aoe",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));

    // Illidan: Agonizing Flames -> avoid
    triggers.push_back(new TriggerNode("bt illidan agonizing flames",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));
}

void RaidBtStrategy::InitMultipliers(std::vector<Multiplier*>& /*multipliers*/)
{
}


