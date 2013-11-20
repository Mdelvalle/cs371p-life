// ---------------
// ConwayCell.c++
// ---------------

// INCLUDES
#include "ConwayCell.h"

ConwayCell::ConwayCell(char c)  :
                       AbstractCell() {
    _liveNeighbours = 0;
	if(c == '.')
		AbstractCell::_alive = false;
	else if(c == '*')
		AbstractCell::_alive = true;
}

char ConwayCell::print() {
	if(AbstractCell::_alive)
		return '*';
	else
		return '.';
}

char ConwayCell::print_live_neighbours() {
	return _liveNeighbours + '0';
}