// -------------
// ConwayCell.h
// -------------

#ifndef ConwayCell_h
#define ConwayCell_h

// INCLUDES
#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	public:
		ConwayCell();
		void inc_age();

		virtual void alive(bool);
		virtual bool alive();
        virtual void liveNeighbours(int);
        virtual int liveNeighbours();
		virtual std::string type();
		virtual bool can_mutate();
		virtual void mutate();
		virtual std::istream& read (std::istream&);
		virtual std::ostream& write (std::ostream&) const;
		virtual ConwayCell* clone() const;
};

#endif // ConwayCell_h
