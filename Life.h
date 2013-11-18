#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

//template <typename T>
class Life {
private:
	vector<vector<char> > grid;
	int rows;
	int columns;

public:
	void store_cells(istream& r) {
		// Store rows and columns
		r >> rows;
		assert(rows > 0);
		r >> columns;
		assert(columns > 0);

		string line;
		int count = 0;
		getline(r, line);
		while(getline(r, line)) {
			vector<char> temp;
			stringstream s(line);
			char c;

			while(s >> c) {
				temp.push_back(c);
			}
			grid.push_back(temp);
			++count;
		}
	}

	void print_grid() {
		cout << rows << endl;
		cout << columns << endl;
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < columns; ++j) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
};