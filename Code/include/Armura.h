#ifndef ARMURA_H
#define ARMURA_H

class Armura
{
    int protectie,greutate,precizie,tip;
public:
    Armura();
    virtual ~Armura();

    int get_protectie() const;
    int get_tip() const;
    int get_greutate() const;
    int get_precizie() const;
    void set_protectie(int x)
    {
        protectie=x;
    }
    void set_tip(int x)
    {
        tip=x;
    }
    void set_greutate(int x)
    {
        greutate=x;
    }
    void set_precizie(int x)
    {
        precizie=x;
    }
};

#endif // ARMURA_H
