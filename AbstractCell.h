// ---------------
// AbstractCell.h
// ---------------

#ifndef AbstractCell_h
#define AbstractCell_h

// INCLUDES
#include <iostream> // istream, ostream
#include <utility> // !=

class AbstractCell {
/*  friend bool operator == (const AbstractCell& lhs, const AbstractCell& rhs) {
        return lhs.equals(rhs);}

    friend std::istream& operator >> (std::istream& lhs, AbstractCell& rhs) {
        return rhs.read(lhs);}

    friend std::ostream& operator << (std::ostream& lhs, const AbstractCell& rhs) {
        return rhs.write(lhs);}*/

public:
	bool _alive;

	AbstractCell();

  virtual void mutate() = 0;
  virtual std::string type() = 0;
  virtual AbstractCell* clone() const = 0;
  virtual std::istream& read (std::istream& in) = 0;
  virtual std::ostream& write (std::ostream& out) const = 0;
};

#endif // AbstractCell_h
