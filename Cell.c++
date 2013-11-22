// ---------
// Cell.c++
// ---------

// INCLUDES
#include "Cell.h"

Cell::Cell() : Handle(new FredkinCell()) {
	ac = get();
}

Cell::Cell(AbstractCell* p) : 
	Handle<AbstractCell> (p) {
    ac = p;
}

void Cell::alive(bool b) {
    get()->_alive = b;
}

bool Cell::alive() {
    return get()->_alive;
}

void Cell::liveNeighbours(int b) {
    get()->_liveNeighbours = b;
}

int Cell::liveNeighbours() {
    return get()->_liveNeighbours;
}

std::string Cell::type() {
    return get()->type();
}

void Cell::inc_age() {
	ac->inc_age();
}

bool Cell::can_mutate() {
	return ac->can_mutate();
}

void Cell::mutate () {
    Cell c(new ConwayCell());
    ac->_alive = true;
    swap(c);
}

std::istream& Cell::read (std::istream& in) {
    return get()->read(in);}

std::ostream& Cell::write (std::ostream& out) const {
    return get()->write(out);}
