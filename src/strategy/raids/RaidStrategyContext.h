#ifndef _PLAYERBOT_RAIDSTRATEGYCONTEXT_H_
#define _PLAYERBOT_RAIDSTRATEGYCONTEXT_H_

#include "Strategy.h"
#include "RaidAq20Strategy.h"
#include "RaidMcStrategy.h"
#include "RaidBwlStrategy.h"
#include "RaidKarazhanStrategy.h"
#include "RaidNaxxStrategy.h"
#include "RaidOsStrategy.h"
#include "RaidEoEStrategy.h"
#include "RaidVoAStrategy.h"
#include "RaidKaraStrategy.h"
#include "RaidZaStrategy.h"
#include "gruulslair/RaidGruulStrategy.h"
#include "magtheridon/RaidMagStrategy.h"
#include "serpentshrine/RaidSscStrategy.h"
#include "theeye/RaidTkStrategy.h"
#include "hyjal/RaidHyjalStrategy.h"
#include "blacktemple/RaidBtStrategy.h"
#include "sunwell/RaidSwpStrategy.h"
#include "RaidUlduarStrategy.h"
#include "RaidOnyxiaStrategy.h"
#include "RaidIccStrategy.h"

class RaidStrategyContext : public NamedObjectContext<Strategy>
{
public:
    RaidStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        creators["aq20"] = &RaidStrategyContext::aq20;
        creators["mc"] = &RaidStrategyContext::mc;
        creators["bwl"] = &RaidStrategyContext::bwl;
        creators["karazhan"] = &RaidStrategyContext::karazhan;
        creators["naxx"] = &RaidStrategyContext::naxx;
        creators["wotlk-os"] = &RaidStrategyContext::wotlk_os;
        creators["wotlk-eoe"] = &RaidStrategyContext::wotlk_eoe;
        creators["voa"] = &RaidStrategyContext::voa;
        creators["uld"] = &RaidStrategyContext::uld;
        creators["onyxia"] = &RaidStrategyContext::onyxia;
        creators["za"] = &RaidStrategyContext::za;
        creators["gruul"] = &RaidStrategyContext::gruul;
        creators["magtheridon"] = &RaidStrategyContext::magtheridon;
        creators["ssc"] = &RaidStrategyContext::ssc;
        creators["tk"] = &RaidStrategyContext::tk;
        creators["hyjal"] = &RaidStrategyContext::hyjal;
        creators["bt"] = &RaidStrategyContext::bt;
        creators["swp"] = &RaidStrategyContext::swp;
        creators["kara"] = &RaidStrategyContext::kara;
        creators["icc"] = &RaidStrategyContext::icc;
    }

private:
    static Strategy* aq20(PlayerbotAI* botAI) { return new RaidAq20Strategy(botAI); }
    static Strategy* mc(PlayerbotAI* botAI) { return new RaidMcStrategy(botAI); }
    static Strategy* bwl(PlayerbotAI* botAI) { return new RaidBwlStrategy(botAI); }
    static Strategy* karazhan(PlayerbotAI* botAI) { return new RaidKarazhanStrategy(botAI); }
    static Strategy* naxx(PlayerbotAI* botAI) { return new RaidNaxxStrategy(botAI); }
    static Strategy* wotlk_os(PlayerbotAI* botAI) { return new RaidOsStrategy(botAI); }
    static Strategy* wotlk_eoe(PlayerbotAI* botAI) { return new RaidEoEStrategy(botAI); }
    static Strategy* voa(PlayerbotAI* botAI) { return new RaidVoAStrategy(botAI); }
    static Strategy* onyxia(PlayerbotAI* botAI) { return new RaidOnyxiaStrategy(botAI); }
    static Strategy* uld(PlayerbotAI* botAI) { return new RaidUlduarStrategy(botAI); }
    static Strategy* icc(PlayerbotAI* botAI) { return new RaidIccStrategy(botAI); }
    static Strategy* za(PlayerbotAI* botAI) { return new RaidZaStrategy(botAI); }
    static Strategy* kara(PlayerbotAI* botAI) { return new RaidKaraStrategy(botAI); }
    static Strategy* gruul(PlayerbotAI* botAI) { return new RaidGruulStrategy(botAI); }
    static Strategy* magtheridon(PlayerbotAI* botAI) { return new RaidMagStrategy(botAI); }
    static Strategy* ssc(PlayerbotAI* botAI) { return new RaidSscStrategy(botAI); }
    static Strategy* tk(PlayerbotAI* botAI) { return new RaidTkStrategy(botAI); }
    static Strategy* hyjal(PlayerbotAI* botAI) { return new RaidHyjalStrategy(botAI); }
    static Strategy* bt(PlayerbotAI* botAI) { return new RaidBtStrategy(botAI); }
    static Strategy* swp(PlayerbotAI* botAI) { return new RaidSwpStrategy(botAI); };
};

#endif
