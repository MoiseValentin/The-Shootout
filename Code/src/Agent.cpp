#include <iostream>

using namespace std;
#include "Agent.h"



void Agent::set_position(const Position& new_position)
{
    position.row = new_position.row;
    position.column = new_position.column;
}

Agent::Position Agent::get_position()const
{
    return position;
}
int Agent::get_hp() const
{
    return hp;
}
void Agent::set_hp(int x)
{
    hp=x;
}
int Agent::get_tag() const
{
    return tag;
}
void Agent::set_tag(int x)
{
    tag=x;
}

void Agent::set_arma(int x)
{
    if(x==1)
    {
        arma.set_dmg(70);
        arma.set_distanta(6);
        arma.set_precizie(8);
        arma.set_tip(1);
    }
    else if(x==2)
    {
        arma.set_dmg(50);
        arma.set_distanta(8);
        arma.set_precizie(6);
        arma.set_tip(2);
    }
    else if(x==3)
    {
        arma.set_dmg(150);
        arma.set_distanta(3);
        arma.set_precizie(10);
        arma.set_tip(3);
    }
}
void Agent::set_armura(int x)
{
    if(x==1)
    {
        armura.set_protectie(100);
        armura.set_greutate(3);
        armura.set_precizie(0);
        armura.set_tip(1);
        int y;
        y=get_hp();
        y=y+armura.get_protectie();
        set_hp(y);
    }
    else if(x==2)
    {
        armura.set_protectie(50);
        armura.set_greutate(2);
        armura.set_precizie(1);
        armura.set_tip(2);
        int y;
        y=get_hp();
        y=y+armura.get_protectie();
        set_hp(y);
    }
    else if(x==3)
    {
        armura.set_protectie(20);
        armura.set_greutate(1);
        armura.set_precizie(2);
        armura.set_tip(3);
        int y;
        y=get_hp();
        y=y+armura.get_protectie();
        set_hp(y);
    }
    else
        armura.set_tip(0);
}
