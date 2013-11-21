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
    	Cell();
    	Cell(AbstractCell* p);
    	std::string type();

    	virtual void mutate();
    	virtual std::istream& read (std::istream&);
    	virtual std::ostream& write (std::ostream&) const;
};

#endif // Cell_h
