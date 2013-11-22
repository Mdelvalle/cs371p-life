// ---------------
// AbstractCell.h
// ---------------

#ifndef AbstractCell_h
#define AbstractCell_h

// INCLUDES
#include <iostream> // istream, ostream
#include <utility> // !=

class AbstractCell {

public:
	bool _alive;
  int _liveNeighbours;

	AbstractCell();

  virtual void alive(bool) = 0;
  virtual bool alive() = 0;
  virtual void liveNeighbours(int) = 0;
  virtual int liveNeighbours() = 0;
  virtual void inc_age() = 0;
  virtual bool can_mutate() = 0;
  virtual void mutate() = 0;
  virtual std::string type() = 0;
  virtual AbstractCell* clone() const = 0;
  virtual std::istream& read (std::istream& in) = 0;
  virtual std::ostream& write (std::ostream& out) const = 0;
};

#endif // AbstractCell_h
