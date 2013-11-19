// -------------
// ConwayCell.h
// -------------

#ifndef ConwayCell_h
#define ConwayCell_h

class ConwayCell : AbstractCell {
protected:
	virtual bool equals(const AbstractCell& that) const {
		if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
			return AbstractCell::equals(*p) && (_age == p->_age);
		return false;
	}

public:
	ConwayCell(char);
	char print();
};

#endif // ConwayCell_h
