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

public:
	int _liveNeighbours;
	FredkinCell();
	char print();
	void inc_age();
	std::string type();

	virtual FredkinCell* clone() const;
	virtual std::istream& read (std::istream&);
	virtual std::ostream& write (std::ostream&) const;
};

#endif // FredkinCell_h
