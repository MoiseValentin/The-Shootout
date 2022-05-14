#include <iostream>
#include <time.h>

using namespace std;

#include "Game_engine.h"
#include "World.h"

int main()
{
    srand(time(NULL));
    Game G;
    G.print_state();//starea initiala
    int i,r=0;
    cout<<endl;
    cout<<"\n 0-Stop the game 1-Next round 2-Complete simulation\n\n=>";


    cin>>i;
    if(i==2) //simulare runde pana la final
    {
        do
        {
            r++;
            cout<<"\nRound "<< r<<endl;
            G.run_round();
            if(G.get_game_over())
                return 0;

        }
        while(i == 2);
    }
    else if(i==1)
        do  //rulare runde cat timp doreste utilizatorul
        {
            r++;
            cout<<"\nRound "<< r<<endl;
            G.run_round();

            if(G.get_game_over())
                return 0;
            cout << "\nContinue? 0-NO/1-YES\n=>";
            cin >> i;
        }
        while(i == 1);
    cout << endl;
    return 0;
}

