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

class Cell : public Handle<AbstractCell> {
	public:
/*		bool _alive;
		int _liveNeighbours;*/
    	AbstractCell* ac;
    	Cell();
    	Cell(AbstractCell* p);

        // virtual void set_liveliness();
        virtual void alive(bool);
        virtual bool alive();
        virtual void liveNeighbours(int);
        virtual int liveNeighbours();
    	virtual void inc_age();
		virtual std::string type();
		virtual bool can_mutate();
    	virtual void mutate();
    	virtual std::istream& read (std::istream&);
    	virtual std::ostream& write (std::ostream&) const;
};

#endif // Cell_h
