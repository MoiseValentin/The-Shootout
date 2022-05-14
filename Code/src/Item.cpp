#include <iostream>

using namespace std;
#include "Item.h"


void Item::set_position(const Position& new_position) {
	position.row = new_position.row;
	position.column = new_position.column;
}

Item::Position Item::get_position()const {
	return position;
}
