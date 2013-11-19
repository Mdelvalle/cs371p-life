#include "FredkinCell.h"

FredkinCell::FredkinCell() {
	_age = 0;
}

char FredkinCell::print() {
	if(age < 10)
		return static_cast<char>(age);
	else if(age >= 10)
		return '+';
	else
		return '-';
}