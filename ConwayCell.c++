// ---------------
// ConwayCell.c++
// ---------------

// INCLUDES
#include "ConwayCell.h"

/*ConwayCell::ConwayCell(char c)  :
                       AbstractCell() {
    _liveNeighbours = 0;
	if(c == '.')
		AbstractCell::_alive = false;
	else if(c == '*')
		AbstractCell::_alive = true;
}*/

ConwayCell::ConwayCell() : AbstractCell() {
	_liveNeighbours = 0;
}

void ConwayCell::alive(bool b) {
	AbstractCell::_alive = b;
}

bool ConwayCell::alive() {
    return AbstractCell::_alive;
}

void ConwayCell::liveNeighbours(int b) {
	AbstractCell::_liveNeighbours = b;
}

int ConwayCell::liveNeighbours() {
	return AbstractCell::_liveNeighbours;
}

bool ConwayCell::can_mutate() {
	//std::cout << "in mutate CONW" << std::endl;
	return false;
}

void ConwayCell::mutate() {
	// Pass	
}

/*void ConwayCell::set_liveliness() {

}*/

std::istream& ConwayCell::read (std::istream& in) {
	char c;
	in >> c;

	if(c == '.')
		AbstractCell::_alive = false;
	else if(c == '*')
		AbstractCell::_alive = true;
	return in;
}

std::ostream& ConwayCell::write (std::ostream& out) const {
	if(AbstractCell::_alive)
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
