#include <iostream>

using namespace std;

#include "Brave_agent.h"
#include "World.h"


Agent::Position Brave_agent::choose_new_position(const World& world) const {
	Position p(0,0);
	Position border1(position.row-10,position.column-10),border2(position.row+10,position.column+10);
	int n = world.get_number_of_rows();
	int m = world.get_number_of_cols();
	int u,o;
	if(armura.get_greutate()==1){u=7;o=-7;}
    if(armura.get_greutate()==2){u=3;o=-3;}
    if(armura.get_greutate()==3){u=2;o=-2;}
	u=4;o=-4;
	int X[2]={u,o} ,Y[2]={u,o};//vectori de stabilire a urmatoarei pozitii in matrice
	//fixam limitele arei vizuale a agentului
	bool ok = false;
	int i=border1.row,j;
	//cautam un agent in zona vizibila
	while(!ok && i<=border2.row) {
		j=border1.column;
		p.row = i;
		while(!ok && j<=border2.column) {
		    p.column = j;
			if(p.row>=0 && p.row<n && p.column>=0 && p.column<m && !(p==position))
				if(world.get_agent(p.row,p.column)){
					ok=true;//daca gasim atunci avem urmatoarea locatie a agentului curajos
				}
			j++;
		}
		i++;
	}
	if(ok==true){
            Agent *ag;ag=world.get_agent(p.row,p.column);
            cout<<"Agentul "<<get_tag()<<" se indreapta catre agentul "<<ag->get_tag()<<endl;
    int x1,y1,abs1,abs2,s,x2,y2,smin;
    x1=p.row;y2=p.column;
    smin=world.get_number_of_rows()*world.get_number_of_cols();
    Position border1(position.row-u,position.column-u),border2(position.row+u,position.column+u);
    int i=border1.row,j;
	//cautam un agent in zona vizibila
	while(i<=border2.row) {
		j=border1.column;
		p.row = i;
		abs1=abs(i-x1);
		while(j<=border2.column) {
		    abs2=abs(j-y2);
		    p.column = j;
			if(p.row>=0 && p.row<n && p.column>=0 && p.column<m && !(p==position))
            {

                s=abs1+abs2;
                if(s<smin){smin=s;
                            x2=i;
                            y2=j;
                            }
            }

			j++;
		}
		i++;
	}
	p.row=x2;
	p.column=y2;

	}

   if(!ok)//daca nu gasim alegem random o pozitie la distanta  2 de cea actuala
	    while(!ok) {
			int i,j;
			i= rand()%2;
			j= rand()%2;
			p.row = position.row+X[i];
			p.column = position.column+Y[j];
			if(p.row>=0 && p.row<n && p.column>=0 && p.column<m )
				ok = true;
            cout<<"Agentul "<<get_tag()<<" nu a gasit niciun oponent"<<endl;

		}


return p;
}
bool Brave_agent::can_attack(const World& world) const {
	Position p(0,0);
	int dist=arma.get_distanta();
	Position border1(position.row-dist,position.column-dist),border2(position.row+dist,position.column+dist);
	int n = world.get_number_of_rows();
	int m = world.get_number_of_cols();
	int i=border1.row,j;
	//cautam un agent in zona vizibila
	while(i<=border2.row) {
		j=border1.column;
		p.row = i;
		while(j<=border2.column) {
		    p.column = j;
			if(p.row>=0 && p.row<n && p.column>=0 && p.column<m && !(p==position))
				if(world.get_agent(p.row,p.column))
                {
                    int x,sem=1;
                    Agent *q;
                    q=world.get_agent(p.row,p.column);
                    if(arma.get_precizie()==6){if(armura.get_precizie()==2)sem=1;
                                                    else if(armura.get_precizie()==1){x = rand() % 10+1;if(x==5||x==7)sem=0;}
                                                                else {x = rand() % 10+1;if(x==1||x==3||x==5||x==7)sem=0;}
                                              }
                    if(arma.get_precizie()==8){if(armura.get_precizie()==2)sem=1;
                                                    else if(armura.get_precizie()==1){x = rand() % 10+1;if(x==5)sem=0;}
                                                                else {x = rand() % 10+1;if(x==1||x==10)sem=0;}

                                                }
                    if(sem!=0){
                    int hpnou;
                    hpnou=q->get_hp();
                    hpnou=hpnou-arma.get_dmg();
                    q->set_hp(hpnou);
                   cout<<"Agentul "<<get_tag()<<" i-a provocat "<<arma.get_dmg()<<" daune agentului "<<q->get_tag()<<endl;
                    if(hpnou<=0)cout<<"Agentul "<<q->get_tag()<<" a fost infrant"<<endl;
                    }
                    else cout<<"Agentul "<<get_tag()<<" l-a ratat pe agentul "<<q->get_tag()<<endl;
                    return true;//daca gasim atunci avem urmatoarea locatie a agentului curajos
                }

			j++;
		}
		i++;
	}

return false;

}
