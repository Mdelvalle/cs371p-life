// -------
// Life.h
// -------

#ifndef Life_h
#define Life_h

// INCLUDES
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <fstream>

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// using namespace std;

template <typename T>
class Life {
private:
	std::vector<std::vector<T> > _grid;
	int _rows;
	int _columns;


public:
	void store_cells(std::istream& in) {
		// Store _rows and _columns
		in >> _rows;
		assert(_rows > 0);
		in >> _columns;
		assert(_columns > 0);

		_grid.resize(_rows+2);
		// Store chars in _grid vector
		for(int i = 0; i < (_rows + 2); ++i) {
			_grid[i].resize(_columns+2);
			for(int j = 0; j < (_columns + 2); ++j) {
				if((i == 0) || (i == _rows+1) || (j == 0) || (j == _columns+1))
					_grid[i][j].alive(false);
				else
					_grid[i][j].read(in);
			}
		}
	}

	// return live neighbours of cell in interior
	int in_interior(int row, int col, std::string type) {
		int count = 0;

		// ConwayCell
		if(type == "ConwayCell") {
			if(_grid[row-1][col].alive())	// Top
				++count;
			if(_grid[row-1][col-1].alive())	// Top-left
				++count;
			if(_grid[row][col-1].alive())	// Left
				++count;
			if(_grid[row+1][col-1].alive())	// Bottom-left
				++count;
			if(_grid[row+1][col].alive())	// Bottom
				++count;
			if(_grid[row+1][col+1].alive())	// Bottom-right
				++count;
			if(_grid[row][col+1].alive())	// Right
				++count;
			if(_grid[row-1][col+1].alive())	// Top-right
				++count;

			return count;
		}

		// FredkinCell
		else if(type == "FredkinCell") {
			if(_grid[row-1][col].alive())	// Top
				++count;
			if(_grid[row+1][col].alive())	// Bottom
				++count;
			if(_grid[row][col+1].alive())	// Right
				++count;
			if(_grid[row][col-1].alive())	// Left
				++count;

			return count;
		}
		return count;
	}

	// Count live neighbours of each cell to see if it dies or lives
	void live_neighbours() {
		for(int i = 1; i <= _rows; ++i) {
			for(int j = 1; j <= _columns; ++j) {
				_grid[i][j].liveNeighbours(in_interior(i, j, _grid[i][j].type()));
			}
		}
	}

	// Counts the total number of live cells in the grid
	int live_cells() {
		int count = 0;
		for(int i = 1; i <= _rows; ++i) {
			for(int j = 1; j <= _columns; ++j) {
				if(_grid[i][j].alive())
					++count;
			}
		}
		return count;
	}

	void print(std::ostream& out, int nth) {
    out << "Generation = " << nth << ", Population = " << live_cells() << std::endl;
		for(int i = 1; i <= _rows; ++i) {
			for(int j = 1; j <= _columns; ++j) {
				_grid[i][j].write(out);
			}
			out << std::endl;
		}
		out << std::endl;
	}

	void simulate(int moves, int print_times, std::ostream& out) {
		int gen = 1;
    	while(moves > 0) {
      		live_neighbours();
		  	std::vector<std::vector<T> > previous_grid(_grid);

	  		for(int i = 1; i <= _rows; ++i) {
			  	for(int j = 1; j <= _columns; ++j) {

			  		// ConwayCell
			  		if(_grid[i][j].type() == "ConwayCell") {
				  		// a dead cell becomes a live cell, if exactly 3 neighbors are alive
				  		if(!previous_grid[i][j].alive() && (previous_grid[i][j].liveNeighbours() == 3))
				  			_grid[i][j].alive(true);

				  		// a live cell becomes a dead cell, if less than 2 or more than 3 neighbors are alive
			  			else if(previous_grid[i][j].alive() && ((previous_grid[i][j].liveNeighbours() < 2) ||
				  										   	(previous_grid[i][j].liveNeighbours() > 3)))
				  			_grid[i][j].alive(false);
				  	}

			  		// FredkinCell
			  		else if(_grid[i][j].type() == "FredkinCell") {
		  				// a dead cell becomes a live cell, if 1 or 3 neighbors are alive
	  					if(!previous_grid[i][j].alive() && (previous_grid[i][j].liveNeighbours() == 1 ||
							   							     previous_grid[i][j].liveNeighbours() == 3)) {
  							_grid[i][j].alive(true);
  						}

		  				// a live cell becomes a dead cell, if 0, 2, or 4 neighbors are alive
	  					else if(previous_grid[i][j].alive() && ((previous_grid[i][j].liveNeighbours() == 0) ||
							  								   (previous_grid[i][j].liveNeighbours() == 2) ||
					  										   (previous_grid[i][j].liveNeighbours() == 4))) {
				  			_grid[i][j].alive(false);
				  		}

				  		// cell remains alive, so increment its age
                		else if(_grid[i][j].alive()) {
				  			_grid[i][j].inc_age();
				  			if(_grid[i][j].can_mutate()) {
				  				_grid[i][j].mutate();
				  			}
						}
				  	}
			  	}
		  	}
        	if(gen < print_times) {
        		print(out, gen);
        		++gen;
      		}
      		--moves;
    	}
	}
};

#endif // Life_h
