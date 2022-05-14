#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include <string>

using namespace std;

#include "world.h"


class Game
{
    World *w;
    int game_over;


public :
    Game();
    void run_round();
    void print_state();
    bool  get_game_over()
    {
        if(game_over==1)
            return true;
        return false;
    }
    ~Game()
    {
        delete w;
    }

};
#endif
