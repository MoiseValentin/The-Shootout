#include <iostream>
#include <fstream>
using namespace std;

#include "Agent.h"
#include "game_engine.h"
#include "Agent_normal.h"
#include "World.h"

//initializare lume si plasare agenti pe harta
Game::Game()
{
    cout<<"The game started!!!"<<endl;
    ifstream F("fisier.txt");
    int x,y,z;
    F >> x >> y;
    w = new World(x,y);
    F >> z;
    for(int i=1; i<=z; i++)
    {
        Agent::Position p(0,0);
        F >> p.row >> p.column;
        Agent *a;
        a = new Agent_normal(p);
        a->set_tag(i);

        cout<<"Agent "<<a->get_tag()<<" equipped : ";
        int q;
        Arma qq;
        qq=a->arma;
        Armura qqq;
        qqq=a->armura;
        q=qq.get_tip();
        if(q==1)
            cout<<"pistol     (dmg: 70  range: 6  accuracy: 80%  )";
        if(q==2)
            cout<<"rifle      (dmg: 50  range: 8  accuracy: 60%  )";
        if(q==3)
            cout<<"shotgun    (dmg: 150 range: 3  accuracy: 100% )";
        q=qqq.get_tip();
        if(q==0)
            cout<<endl;
        if(q==1)
            cout<<" and heavy armor   (+100 hp  -50% mobility)"<<endl;
        if(q==2)
            cout<<" and medium armor  (+50 hp  +50% accuracy -25% mobility)"<<endl;
        if(q==3)
            cout<<" and light armor   (+20 hp  +100% accuracy +75% mobility)"<<endl;
        w->add_agent(a,p.row,p.column);
    }

    game_over=0;
}

ostream &operator <<(ostream &out,World &wm)
{
    out <<endl <<" ";                 //supraincarcarea operatorului de afisare pentru a afisa harta intreaga
    for(int i=0; i<2*wm.get_number_of_cols(); i++)
        out << (char)196;
    out << endl;
    for(int i=0; i<wm.get_number_of_rows(); i++)
    {
        out <<(char)179;
        for(int j=0; j<wm.get_number_of_cols(); j++)
            if(wm.get_agent(i,j)!=NULL)
                out << wm.get_agent(i,j)->get_agent_type()<<" ";
            else
                cout<<" "<<" ";
        out << (char)179;
        out << endl;
    }
    out <<" ";
    for(int i=0; i<2*wm.get_number_of_cols(); i++)
        out << (char)196;
    return out;
}

void Game::run_round()
{
    Agent::Position p(0,0);
    //functie pentru fiecare runda de joc
    unsigned i = 0;
    vector<Agent*> b;
    b = w->get_all_agents();//fiecare agent alege ce sa faca
    while( i<b.size())
    {
        Agent *a;
        Agent::Position q(0,0);
        a = b[i];
        if(a->can_attack(*w)==true)//daca vede un oponent si il poate ataca o va face, altfel merge spre el
        {
            unsigned j = 0;
            Agent *c;
            while(j<b.size())
            {
                c=b[j];
                if(c->get_hp()<=0)
                {
                    w->remove_agent(c);
                    delete c;
                }
                j++;
            }
            b=w->get_all_agents();

        }
        else
        {
            p = a->choose_new_position(*w);//daca nu vede niciun oponent merge random
            q = a->get_position();
            w->move_agent(a,p.row,p.column);

        }

        i++;

    }
    cout<<endl<<*w;//afisare harta
    if(b.size()==1)
    {
        cout<<endl<<"Agent "<<b[0]->get_tag()<<" won!"<<endl<<endl;
        game_over=1;
    }
}

void Game::print_state()
{
    cout << *w;
}
