// -------------
// ConwayCell.h
// -------------

// INCLUDES
#include "ConwayCell.h"

ConwayCell::ConwayCell(char c) {
	if(c == '.')
		AbstractCell::_alive = false;
	else if(c == '*')
		AbstractCell::_alive = true;
}

char ConwayCell::print() {
	if(alive)
		return '*';
	else
		return '.';
}
