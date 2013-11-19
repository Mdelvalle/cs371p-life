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

	void store_cells(istream& r) {
		// Store _rows and _columns
		r >> _rows;
		assert(_rows > 0);
		r >> _columns;
		assert(_columns > 0);

		// Store chars in _grid vector
		string line;
		int count = 0;
    int row = 0;
    int col = 0;
		getline(r, line);

		while(getline(r, line)) {
      assert(line != NULL);

			vector<T> temp_grid;
			stringstream s(line);
			char c;

			while(s >> c) {
				T cell(c, row, col);
				temp_grid.push_back(cell);
        ++col;
			}
			_grid.push_back(temp_grid);
      col = 0;
      ++row;
			++count;
		}
	}


public:
	Life(ifstream& f) {
		store_cells(f);
	}

	void print(ofstream& f) {
		f << _rows << endl;
		f << _columns << endl;
		for(int i = 0; i < _rows; ++i) {
			for(int j = 0; j < _columns; ++j) {
				f << _grid[i][j];
			}
			f << endl;
		}
		f << endl;
	}
};

#endif // Life_h
