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

void ConwayCell::mutate() {
	
}

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

void ConwayCell::inc_age() {}

ConwayCell* ConwayCell::clone() const {
    return new ConwayCell(*this);
}