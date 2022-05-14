#include "Arma.h"

Arma::Arma()
{
}

Arma::~Arma()
{
    //dtor
}
int Arma::get_dmg() const
{
    return dmg;
}

int Arma::get_precizie() const
{
    return precizie;
}

int Arma::get_distanta() const
{
    return distanta;
}
int Arma::get_tip() const
{
    return tip;
}
