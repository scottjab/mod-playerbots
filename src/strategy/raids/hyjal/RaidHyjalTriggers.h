#ifndef _PLAYERBOT_RAIDHYJALTRIGGERS_H
#define _PLAYERBOT_RAIDHYJALTRIGGERS_H

#include "Trigger.h"

class HyjalArchimondeDoomfireTrigger : public Trigger
{
public:
    HyjalArchimondeDoomfireTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal archimonde doomfire") {}
    bool IsActive() override;
};

class HyjalArchimondeAirBurstTrigger : public Trigger
{
public:
    HyjalArchimondeAirBurstTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal archimonde air burst") {}
    bool IsActive() override;
};

class HyjalWinterchillDeathAndDecayTrigger : public Trigger
{
public:
    HyjalWinterchillDeathAndDecayTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal winterchill death and decay") {}
    bool IsActive() override;
};

class HyjalWinterchillIceboltTrigger : public Trigger
{
public:
    HyjalWinterchillIceboltTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal winterchill icebolt") {}
    bool IsActive() override;
};

class HyjalAnetheronCarrionSwarmTrigger : public Trigger
{
public:
    HyjalAnetheronCarrionSwarmTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal anetheron carrion swarm") {}
    bool IsActive() override;
};

class HyjalKazrogalMarkTrigger : public Trigger
{
public:
    HyjalKazrogalMarkTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal kazrogal mark") {}
    bool IsActive() override;
};

class HyjalAzgalorDoomTrigger : public Trigger
{
public:
    HyjalAzgalorDoomTrigger(PlayerbotAI* botAI) : Trigger(botAI, "hyjal azgalor doom") {}
    bool IsActive() override;
};

#endif


