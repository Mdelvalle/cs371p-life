#ifndef ConwayCell_h
#define ConwayCell_h

class ConwayCell : AbstractCell {
private:
	//bool state; // needed here or in other class?

protected:
	virtual bool equals(const AbstractCell& that) const {
		if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
			return AbstractCell::equals(*p) && (_age == p->_age);
		return false;
	}

	virtual std::istream& read(std::istream& in) {
		return AbstractCell::
	}

public:
	ConwayCell();

	char print();
};

#endif