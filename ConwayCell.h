// -------------
// ConwayCell.h
// -------------

#ifndef ConwayCell_h
#define ConwayCell_h

// INCLUDES
#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	public:
		int _liveNeighbours;
		ConwayCell();
		char print();
		std::string type();
		void inc_age();

		virtual std::istream& read (std::istream&);
		virtual std::ostream& write (std::ostream&) const;
		virtual ConwayCell* clone() const;
};

#endif // ConwayCell_h
