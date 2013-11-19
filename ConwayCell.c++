#include "ConwayCell.h"

ConwayCell::ConwayCell(c) {
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