#ifndef PISTOL_H
#define PISTOL_H

#include "World.h"
#include "Arma.h"

class Pistol :public Arma
{
    public:
        Pistol();
        virtual ~Pistol();
        string get_tip_arma()const{ return "Pistol";}
};

#endif // PISTOL_H
