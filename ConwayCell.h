// -------------
// ConwayCell.h
// -------------

#ifndef ConwayCell_h
#define ConwayCell_h

// INCLUDES
#include "AbstractCell.h"

class ConwayCell : AbstractCell {
/*	protected:
		virtual bool equals(const AbstractCell& that) const {
			if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
				return AbstractCell::equals(*p) && (_age == p->_age);
			return false;
		}
*/
	public:
		int _liveNeighbours;
		ConwayCell(char);
		char print();
		char print_live_neighbours();
};

#endif // ConwayCell_h
