// ---------------
// AbstractCell.h
// ---------------

#ifndef AbstractCell_h
#define AbstractCell_h

// INCLUDES
#include <iostream> // istream, ostream
#include <utility> // !=

class AbstractCell {
    friend bool operator == (const AbstractCell& lhs, const AbstractCell& rhs); {
        return lhs.equals(rhs);}

    friend std::istream& operator >> (std::istream& lhs, AbstractCell& rhs); {
        return rhs.read(lhs);}

    friend std::ostream& operator << (std::ostream& lhs, const AbstractCell& rhs); {
        return rhs.write(lhs);}

public:
	bool _alive;
	bool _edge;
	bool _corner;
	bool _interior;

	AbstractCell(int, int);

  bool edge_cell(int, int);
  bool corner_cell(int, int);
  bool interior_cell(int, int);
};

#endif // AbstractCell_h
