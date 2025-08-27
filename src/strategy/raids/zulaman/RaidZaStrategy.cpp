#include "RaidZaStrategy.h"

void RaidZaStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Akil'zon
    triggers.push_back(new TriggerNode("za akilzon electrical storm",
        NextAction::array(0, new NextAction("za move to storm eye", ACTION_EMERGENCY + 5), nullptr)));
    triggers.push_back(new TriggerNode("za static disruption",
        NextAction::array(0, new NextAction("move from group", ACTION_RAID + 2), nullptr)));

    // Nalorakk
    triggers.push_back(new TriggerNode("za nalorakk mangle on tank",
        NextAction::array(0, new NextAction("za swap to bear side", ACTION_RAID + 1), nullptr)));

    // Jan'alai
    triggers.push_back(new TriggerNode("za janalai fire bombs",
        NextAction::array(0, new NextAction("za stack on master during bombs", ACTION_EMERGENCY + 6), new NextAction("avoid aoe", ACTION_EMERGENCY + 5), nullptr)));
    triggers.push_back(new TriggerNode("za janalai flame breath",
        NextAction::array(0, new NextAction("rear flank", ACTION_RAID + 1), nullptr)));

    // Halazzi
    triggers.push_back(new TriggerNode("za halazzi totem",
        NextAction::array(0, new NextAction("za kill halazzi totem", ACTION_RAID + 3), nullptr)));

    // Zul'jin phases
    triggers.push_back(new TriggerNode("za zuljin creeping paralysis",
        NextAction::array(0, new NextAction("use trinket", ACTION_EMERGENCY + 3), nullptr)));
    triggers.push_back(new TriggerNode("za zuljin energy storm",
        NextAction::array(0, new NextAction("za spread for storm", ACTION_EMERGENCY + 3), nullptr)));
    triggers.push_back(new TriggerNode("za zuljin claw rage",
        NextAction::array(0, new NextAction("move from group", ACTION_RAID + 2), nullptr)));
    triggers.push_back(new TriggerNode("za zuljin flame pillars",
        NextAction::array(0, new NextAction("avoid aoe", ACTION_EMERGENCY + 4), nullptr)));
}

void RaidZaStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    // Empty for now
}


