#include "ConwayCell.h"

ConwayCell::ConwayCell() {
	
}

char ConwayCell::print() {
	if(alive)
		return '*';
	else
		return '.';
}