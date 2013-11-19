// --------------
// FredkinCell.h
// --------------

#ifndef FredKinCell_h
#define FredKinCell_h

class FredkinCell : AbstractCell {
private:
	int _age;

protected:
	virtual bool equals(const AbstractCell& that) const {
		if(const FredkinCell* const p = dynamic_cast<const FredkinCell*>(&that))
			return AbstractCell::equals(*p) && (_age == p->_age);
		return false;
	}

public:
	FredkinCell(char, int, int);
	char print();
};

#endif // FredkinCell_h
