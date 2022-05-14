#ifndef AGENT_H_
#define AGENT_H_
#include "Arma.h"
#include "Armura.h"
#include <string>
using namespace std;

class World;

class Agent
{
    int hp,tag;
public:
    Arma arma;
    Armura armura;
    struct Position// clasa imbricata pentru a pastra pozitia unui agent
    {
        int row;
        int column;

        Position(const int r, const int c)
        {
            row = r;
            column = c;
        }

        bool operator==(const Position &p)
        {
            if(p.row==row && p.column==column)
                return true;
            return false;
        }
    };
    void set_position(const Position& new_position);// schimba pozitia agentului
    struct Position position;
    Agent(Position p) : position(p) {}
    virtual ~Agent() {};
    Position get_position() const;//pozitia agentului
    virtual int get_agent_type() const =0;//tipul agentului
    virtual Position choose_new_position(const World& world) const =0;//pozitia noua
    void set_hp(int x);
    void set_arma(int x);
    void set_armura(int x);
    int get_hp() const;
    int get_tag() const;
    void set_tag(int x);
    virtual bool can_attack(const World& world) const =0;
    friend class World;
};

#endif
