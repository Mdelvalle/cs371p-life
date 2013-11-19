#ifndef Cell_h
#define Cell_h

// INCLUDES
#include "Handle.h"
#include "AbstractCell.h"

class Cell : Handle<AbstractCell> {
    Cell(AbstractCell* p) :
            Handle<AbstractCell> (p);
        {}

/*
	Cell (const Cell& that) :
			Handle<AbstractCell> (that)
		{}

	~Cell ()
		{}

	Cell& operator = (const Cell& that) {
		Handle<AbstractCell>::operator=(that);
		return *this;}
*/

};

#endif