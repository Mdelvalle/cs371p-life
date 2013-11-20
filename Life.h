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

using namespace std;

template <typename T>
class Life {
private:
	vector<vector<T> > _grid;
	int _rows;
	int _columns;


public:
	void store_cells(ifstream& r) {
		// Store _rows and _columns
		r >> _rows;
		assert(_rows > 0);
		r >> _columns;
		assert(_columns > 0);

		// Store chars in _grid vector
		string line;
		int count = 0;
		getline(r, line);

		while(getline(r, line)) {
      	assert(line != "");

			vector<T> temp_grid;
			stringstream s(line);
			char c;

			while(s >> c) {
				T cell(c);
				temp_grid.push_back(cell);
			}
			_grid.push_back(temp_grid);
			++count;
		}
	}

	// returns true if cell is in edge, false otherwise
	bool edge_cell(int row, int col) {
		if(((row == 0) || (row == (_rows - 1))) && ((col != 0) && (col != (_columns - 1))) ||
		   (((col == 0) || (col == (_columns - 1))) && ((row != 0) && (row != (_rows - 1)))))
			return true;
		else
			return false;
	}

	// returns true if cell is in corner, false otherwise
	bool corner_cell(int row, int col) {
		if(((row == 0) && (col == 0)) ||
		   ((row == 0) && (col == (_columns - 1))) ||
		   ((row == (_rows - 1)) && (col == (_columns - 1))) ||
		   ((row == (_rows - 1)) && (col == 0)))
			return true;
		else
			return false;
	}

	// return live neighbours of cell in edge
	int in_edge(int row, int col) {
		int count = 0;

		// Top edge
		if(row == 0) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row][col-1]._alive)
					++count;
				if(_grid[row+1][col-1]._alive)
					++count;
				if(_grid[row+1][col]._alive)
					++count;
				if(_grid[row+1][col+1]._alive)
					++count;
				if(_grid[row][col+1]._alive)
					++count;

				return count;


			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Bottom edge
		else if(row == (_rows - 1)) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row][col-1]._alive)
					++count;
				if(_grid[row-1][col-1]._alive)
					++count;
				if(_grid[row-1][col]._alive)
					++count;
				if(_grid[row-1][col+1]._alive)
					++count;
				if(_grid[row][col+1]._alive)
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Left edge
		else if(col == 0) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row+1][col]._alive)
					++count;
				if(_grid[row+1][col+1]._alive)
					++count;
				if(_grid[row][col+1]._alive)
					++count;
				if(_grid[row-1][col+1]._alive)
					++count;
				if(_grid[row-1][col]._alive)
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Right edge
		else {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row+1][col]._alive)
					++count;
				if(_grid[row+1][col-1]._alive)
					++count;
				if(_grid[row][col-1]._alive)
					++count;
				if(_grid[row-1][col-1]._alive)
					++count;
				if(_grid[row-1][col]._alive)
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}
	}

    // return live neighbours of cell in corner
	int in_corner(int row, int col) {
		int count = 0;

		// Top left corner
		if((row == 0) && (col == 0)) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row+1][col]._alive)	// bottom
					++count;
				if(_grid[row+1][col+1]._alive)	// bottom-right
					++count;
				if(_grid[row][col+1]._alive)	// right
					++count;

				return count;


			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Bottom left corner
		else if((row == (_rows - 1)) && (col == 0)) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row-1][col]._alive)	// top
					++count;
				if(_grid[row-1][col+1]._alive)	// top-right
					++count;
				if(_grid[row][col+1]._alive)	// right
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Bottom right corner
		else if((row == (_rows - 1)) && (col == (_columns - 1))) {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row-1][col]._alive)	// top
					++count;
				if(_grid[row-1][col-1]._alive)	// top-left
					++count;
				if(_grid[row][col-1]._alive)	// left
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}

		// Top right corner
		else {
			// if ConwayCell
			// if(c.type() == "ConwayCell")
				if(_grid[row+1][col]._alive)	// bottom
					++count;
				if(_grid[row+1][col-1]._alive)	// bottom-left
					++count;
				if(_grid[row][col-1]._alive)	// left
					++count;

				return count;

			// if FredkinCell
			// if(c.type() == "FredkinCell")
		}
	}

	// return live neighbours of cell in interior
	int in_interior(int row, int col) {
		int count = 0;

		// if ConwayCell
		// if(c.type() == "ConwayCell")
			if(_grid[row-1][col]._alive)	// Top
				++count;
			if(_grid[row-1][col-1]._alive)	// Top-left
				++count;
			if(_grid[row][col-1]._alive)	// Left
				++count;
			if(_grid[row+1][col-1]._alive)	// Bottom-left
				++count;
			if(_grid[row+1][col]._alive)	// Bottom
				++count;
			if(_grid[row+1][col+1]._alive)	// Bottom-right
				++count;
			if(_grid[row][col+1]._alive)	// Right
				++count;
			if(_grid[row-1][col+1]._alive)	// Top-right
				++count;

			return count;

		// if FredkinCell
		// if(c.type() == "FredkinCell")
	}

	// Count live neighbours of each cell to see if it dies or lives
	void live_neighbours() {
		for(int i = 0; i < _rows; ++i) {
			for(int j = 0; j < _columns; ++j) {
				if(edge_cell(i, j))
					_grid[i][j]._liveNeighbours = in_edge(i, j);
				else if(corner_cell(i, j))
					_grid[i][j]._liveNeighbours = in_corner(i, j);
				else
					_grid[i][j]._liveNeighbours = in_interior(i, j);
			}
		}
	}

	void print(ofstream& f) {
		f << _rows << endl;
		f << _columns << endl;
		for(int i = 0; i < _rows; ++i) {
			for(int j = 0; j < _columns; ++j) {
				f << (_grid[i][j]).print_live_neighbours();
			}
			f << endl;
		}
		f << endl;
	}
};

#endif // Life_h
