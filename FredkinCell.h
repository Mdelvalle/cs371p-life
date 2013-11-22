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
	//int _liveNeighbours;
	FredkinCell();
	void inc_age();
	

	virtual void alive(bool);
	virtual bool alive();
    virtual void liveNeighbours(int);
    virtual int liveNeighbours();
  	virtual std::string type();
  	virtual bool can_mutate();
	virtual void mutate();
	virtual FredkinCell* clone() const;
	virtual std::istream& read (std::istream&);
	virtual std::ostream& write (std::ostream&) const;
};

#endif // FredkinCell_h
