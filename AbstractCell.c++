// -----------------
// AbstractCell.c++
// -----------------

// INCLUDES
#include "AbstractCell.h"

AbstractCell::AbstractCell() {
  _alive = false;

/*  _edge = edge_cell(row, col);
  if(_edge) {
    _corner = false;
    _interior = false;
  }
  else {
    _corner = corner_cell(row, col);
    if(_corner)
      _interior = false;
    else
      _interior = true;
  }*/
}

/*bool AbstractCell::edge_cell(int row, int col) {
  if((col == 0) || (col == (_grid_cols - 1)) || (row == 0) || (row == (_grid_rows - 1)))
    return true;
  else
    return false;
}

bool AbstractCell::corner_cell(int row, int col) {
  if(((row == 0) && ((col == 0) || (col == (_grid_cols - 1)))) ||
     ((row == (_grid_rows - 1)) && ((col == 0) || (col == (_grid_cols - 1)))))
    return true;
  else
    return false;
}*/
