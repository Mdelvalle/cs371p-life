// ----------------
// FredkinCell.c++
// ----------------

// INCLUDES
#include "FredkinCell.h"

/*FredkinCell::FredkinCell(char c) :
                         AbstractCell() {
	if(c == '-') {
		_alive = false;
		_age = 0;
	}
	else if(c == '+') {
		_alive = true;
		_age = 10;
	}
	else {
		_age = c - '0';
		_alive = true;
	}
}*/

FredkinCell::FredkinCell() : AbstractCell() {
	_age = 0;
	_alive = true;
	_liveNeighbours = 0;
}

void FredkinCell::alive(bool b) {
	_alive = b;
}

bool FredkinCell::alive() {
    return _alive;
}

void FredkinCell::liveNeighbours(int b) {
	AbstractCell::_liveNeighbours = b;
}

int FredkinCell::liveNeighbours() {
	return AbstractCell::_liveNeighbours;
}

bool FredkinCell::can_mutate() {
	if(_age == 2)
		return true;
	else
		return false;
}

void FredkinCell::mutate() {
	// Pass
}

FredkinCell* FredkinCell::clone() const {
    return new FredkinCell(*this);
}

std::istream& FredkinCell::read (std::istream& in) {
	char c;
	in >> c;

	if(c == '-') {
		_alive = false;
		_age = 0;
	}
	else if(c == '+') {
		_alive = true;
		_age = 10;
	}
	else {
		_alive = true;
		_age = c - '0';
	}
	//std::cout << _alive;
	return in;
}

std::ostream& FredkinCell::write (std::ostream& out) const {
	if(!(_alive))
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