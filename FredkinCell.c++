// ----------------
// FredkinCell.c++
// ----------------

// INCLUDES
#include "FredkinCell.h"

FredkinCell::FredkinCell(char c) :
                         AbstractCell() {
	if(c == '-') {
		AbstractCell::_alive = false;
		_age = 0;
	}
	else if(c == '+') {
		AbstractCell::_alive = true;
		_age = 10;
	}
	else {
		_age = c - '0';
		AbstractCell::_alive = true;
	}
}

char FredkinCell::print() {
	if(!(AbstractCell::_alive))
		return '-';
	else if(_age >= 10)
		return '+';
	else
		return _age + '0';
}

void FredkinCell::inc_age() {
	++_age;
}