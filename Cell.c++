// ---------
// Cell.c++
// ---------

// INCLUDES
#include "Cell.h"

Cell::Cell(AbstractCell* p) : 
	Handle<AbstractCell> (p) {
    ac = p;
}

void Cell::mutate () {
    Cell c = new ConwayCell();
    get()->_alive = true;
    swap(c);
}

std::string Cell::type() {
    return get()->type();
}

std::istream& Cell::read (std::istream& in) {
    return get()->read(in);}

std::ostream& Cell::write (std::ostream& out) const {
    return get()->write(out);}