#ifndef ARMA_H
#define ARMA_H


class Arma
{
    int dmg,distanta,precizie,tip;
public:
    Arma();
    virtual ~Arma();

    int get_dmg() const;
    int get_tip() const;
    int get_distanta() const;
    int get_precizie() const;
    void set_dmg(int x)
    {
        dmg=x;
    }
    void set_tip(int x)
    {
        tip=x;
    }
    void set_distanta(int x)
    {
        distanta=x;
    }
    void set_precizie(int x)
    {
        precizie=x;
    }

};

#endif // ARMA_H
