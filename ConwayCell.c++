// ---------------
// ConwayCell.c++
// ---------------

// INCLUDES
#include "ConwayCell.h"


ConwayCell::ConwayCell() : AbstractCell() {
	_liveNeighbours = 0;
}

void ConwayCell::alive(bool b) {
	_alive = b;
}

bool ConwayCell::alive() {
    return _alive;
}

void ConwayCell::liveNeighbours(int b) {
	_liveNeighbours = b;
}

int ConwayCell::liveNeighbours() {
	return _liveNeighbours;
}

bool ConwayCell::can_mutate() {
	return false;
}

void ConwayCell::mutate() {
	// Pass	
}

std::istream& ConwayCell::read (std::istream& in) {
	char c;
	in >> c;

	if(c == '.')
		_alive = false;
	else if(c == '*')
		_alive = true;
	return in;
}

std::ostream& ConwayCell::write (std::ostream& out) const {
	if(_alive)
		return out << '*';
	else
		return out << '.';
}

std::string ConwayCell::type() {
	return "ConwayCell";
}

void ConwayCell::inc_age() {
	// Pass
}

ConwayCell* ConwayCell::clone() const {
    return new ConwayCell(*this);
}
