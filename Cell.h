// -------
// Cell.h
// -------

#ifndef Cell_h
#define Cell_h

// INCLUDES
#include "Handle.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

class Cell : Handle<AbstractCell> {
	public:
    	AbstractCell* ac;
    	Cell(AbstractCell* p);
    	void mutate();
    	std::string type();

    	virtual std::istream& read (std::istream&);
    	virtual std::ostream& write (std::ostream&) const;
};

#endif // Cell_h
