// ----------------
// FredkinCell.c++
// ----------------

// INCLUDES
#include "FredkinCell.h"

/*FredkinCell::FredkinCell(char c) :
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
}*/

FredkinCell::FredkinCell() : AbstractCell() {
	_liveNeighbours = 0;
}

std::istream& FredkinCell::read (std::istream& in) {
	char c;
	in >> c;

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
	return in;
}

std::ostream& FredkinCell::write (std::ostream& out) const {
	if(!(AbstractCell::_alive))
		return out << '-';
	else if(_age >= 10)
		return out << '+';
	else
		return out << _age;// + '0';
}

void FredkinCell::inc_age() {
	++_age;
}

std::string FredkinCell::type() {
	return "FredkinCell";
}

FredkinCell* FredkinCell::clone() const {
    return new FredkinCell(*this);
}