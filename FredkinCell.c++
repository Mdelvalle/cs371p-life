#include "FredkinCell.h"

FredkinCell::FredkinCell(c) {
	if(c == '-') {
		AbstractCell::_alive = false;
		_age = 0;
	}
	else if(c == '+') {
		AbstractCell::_alive = false;
		_age = 10;
	}
	else {
		_age = c - '0';
		AbstractCell::_alive = true
	}
}

char FredkinCell::print() {
	if(age < 10)
		return static_cast<char>(age);
	else if(age >= 10)
		return '+';
	else
		return '-';
}