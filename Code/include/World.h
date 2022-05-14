#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <string>
using namespace std;

#include "Agent.h"

class World
{
private:
    Agent ***agents_matrix;
    vector<Agent*>  agents;

    const int number_of_rows;
    const int number_of_columns;
public:

    World(const int rows, const int columns);

    virtual ~World();

    int get_number_of_rows() const;
    int get_number_of_cols() const;
    void add_agent(const Agent* agent, const int row, const int column);//adauga un agent nou
    void remove_agent(const Agent* agent);//functie apelata dupa ce un agent este omorat
    vector<Agent*> get_all_agents() const;//returneaza toti agentii
    Agent* get_agent(const int row, const int column) const;//returneaza agentul de pe o pozitie, sau NULL
    void move_agent(Agent* const agent,const int new_row,const int new_column);//muta agentul
};

#endif
