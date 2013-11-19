// -----------------
// AbstractCell.c++
// -----------------

// INCLUDES
#include "AbstractCell.h"

AbstractCell::AbstractCell(int row, int col) {
  _alive = false;
  _edge = edge_cell(row, col);
  _corner = corner_cell(row, col);
  _interior = interior_cell(row, col);
}

AbstractCell::edge_cell(int row, int col) {
  if((col == 0) || (col == (_col - 1)) || (row == 0) || (row == (_row - 1)))
    return true;
  else
    return false;
}

AbstractCell::corner_cell(int row, int col) {
  if(((row == 0) && ((col == 0) || (col == (_col - 1)))) ||
     ((row == (_row - 1)) && ((col == 0) || (col == (_col - 1)))))
    return true;
  else
    return false;
}

AbstractCell::interior_cell() {
  if(!_edge && !_corner)
    return true;
  else
    return false;
}
