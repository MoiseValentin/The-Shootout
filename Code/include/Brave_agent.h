#ifndef _BRAVE_AGENT_H
#define _BRAVE_AGENT_H

#include "World.h"
#include "Agent.h"

//agentul curajos

class Brave_agent :public Agent {
public:
	Brave_agent(const Position &p) : Agent(p){set_hp(100);int x;x = rand() % 3+1;set_arma(x);x = rand() % 4+1;set_armura(x);}
	int get_agent_type()const{ return get_tag();}
	Position choose_new_position(const World& world) const;
    bool can_attack(const World& world) const;
};


#endif
