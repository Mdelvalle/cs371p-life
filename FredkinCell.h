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

	virtual std::istream& read(std::istream& in) {
		return AbstractCell::
	}

public:
	FredkinCell(char c);

	char print();
};

#endif