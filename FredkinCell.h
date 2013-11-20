// --------------
// FredkinCell.h
// --------------

#ifndef FredKinCell_h
#define FredKinCell_h

// INCLUDES
#include "AbstractCell.h"

class FredkinCell : public AbstractCell {
private:
	int _age;

/*protected:
	virtual bool equals(const AbstractCell& that) const {
		if(const FredkinCell* const p = dynamic_cast<const FredkinCell*>(&that))
			return AbstractCell::equals(*p) && (_age == p->_age);
		return false;
	}*/

public:
	int _liveNeighbours;
	FredkinCell(char);
	char print();
	void inc_age();
};

#endif // FredkinCell_h
