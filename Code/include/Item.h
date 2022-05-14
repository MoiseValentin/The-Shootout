#ifndef ITEM_H
#define ITEM_H
#include "Arma.h"
#include "Armura.h"
class World;

class Item
{

public:


	struct Position {
		int row;
		int column;

		Position(const int r, const int c) {
			row = r;
			column = c;
		}

	};

protected:

	void set_position(const Position& new_position);
	struct Position position;
public:

	// Creeaza agentului, initializand variabila position
	// (atentie: trebuie folosite initializers, fiindca
	// clasa Position nu are constructor default)
	Item(Position p) : position(p) {};

	virtual ~Item() {};

	// returneaza pozitia curenta a agentului
	Position get_position() const;

	// Returneaza o string care identifica tipul agentului
	virtual string get_item_type() const =0;

	// Intreaba care este noua pozitie dorita

	// Permite clasa World sa acceseze metoda set_position
	// Asa garantam ca numai clasa World va avea voie sa modifice pozitia
	// agentului
	friend class World;
};


#endif
