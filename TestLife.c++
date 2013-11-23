#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"

using namespace std;

TEST(FredkinCell, fredkin1) {
	FredkinCell test;

	assert(test._alive == true);
}

TEST(FredkinCell, fredkin2) {
	FredkinCell test;

	assert(test.can_mutate() == false);
}

TEST(FredkinCell, fredkin3) {
	FredkinCell test;
	test.inc_age();
	test.inc_age();

	assert(test.can_mutate() == true);
}

TEST(FredkinCell, fredkin4) {
	FredkinCell test;

	assert(test._alive == true);
}

TEST(FredkinCell, fredkin5) {
	FredkinCell test;

	assert(test._alive == true);
}

TEST(FredkinCell, fredkin6) {
	FredkinCell test;

	assert(test.type() == "FredkinCell");
}

TEST(ConwayCell, ConwayCell1) {
	FredkinCell test;

	assert(test._alive == true);
}

TEST(ConwayCell, ConwayCell2) {
	ConwayCell test;

	assert(test.can_mutate() == false);
}

TEST(ConwayCell, ConwayCell3) {
	ConwayCell test;
	test.inc_age();
	test.inc_age();

	assert(test.can_mutate() == false);
}

TEST(ConwayCell, ConwayCell4) {
	ConwayCell test;

	assert(test._alive == true);
}

TEST(ConwayCell, ConwayCell5) {
	ConwayCell test;

	assert(test._alive == true);
}

TEST(ConwayCell, ConwayCell6) {
	ConwayCell test;

	assert(test.type() == "ConwayCell");
}

TEST(Cell, cell1) {
	Cell test;

	assert(test.alive() == true);
}

TEST(Cell, cell2) {
	Cell test;

	assert(test.type() == "FredkinCell");
}

TEST(Cell, cell3) {
	Cell test;

	assert(test.can_mutate() == false);
}

TEST(Cell, cell4) {
	Cell test;
	test.mutate();

	assert(test.type() == "ConwayCell");
}

TEST(Cell, cell5) {
	Cell test;
	test.inc_age();
	test.inc_age();

	assert(test.can_mutate() == true);
}

TEST(Cell, cell6) {
	Cell test;
	test.inc_age();
	test.inc_age();
	test.inc_age();
	test.inc_age();

	assert(test.can_mutate() == false);
}

TEST(Cell, cell7) {
	Cell test;
	test.mutate();

	assert(test.get()->_alive == true);
}

TEST(Cell, cell8) {
	Cell test;
	test.mutate();
	test.alive(false);

	assert(test.alive() == false);
}

TEST(Cell, cell9) {
	Cell test;
	test.mutate();
	test.get()->_alive = false;

	assert(test.get()->_alive == false);
}

TEST(Cell, cell10) {
	Cell test;
	test.mutate();
	test.alive(true);

	assert(test.alive() == true);
}

TEST(Life, life1) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}

	assert(test._grid[0][0]._alive == true);
}

TEST(Life, life2) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[0][0]._alive = false;

	assert(test._grid[0][0]._alive == false);
}

TEST(Life, life3) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[3][3]._alive = false;

	assert(test._grid[3][3]._alive == false);
}

TEST(Life, life4) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}

	assert(test.live_cells() == 0);
}

TEST(Life, life5) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);

			test._grid[i][j]._alive = true;
		}
	}

	assert(test.live_cells() == 0);
}

TEST(Life, life6) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
			test._grid[i][j]._alive = true;
		}
	}
	assert(test.in_interior(3, 3, "ConwayCell") == 8);
}

TEST(Life, life7) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
			test._grid[i][j]._alive = true;
		}
	}
	assert(test.in_interior(3, 3, "ConwayCell") == 8);
}

TEST(Life, life8) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
			test._grid[i][j]._alive = true;
		}
	}
	assert(test.in_interior(3, 3, "ConwayCell") != 5);
}

TEST(Life, life9) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	assert(test.live_cells() != 25);
}

TEST(Life, life10) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[1][1]._alive = false;

	assert(test._grid[1][1]._alive != true);
}

TEST(Life, life11) {
	Life<ConwayCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[2][2]._alive = false;

	assert(test._grid[2][2]._alive == false);
}

TEST(Life, life12) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
			test._grid[i][j]._alive = true;
		}
	}
	assert(test.in_interior(3, 3, "FredkinCell") != 5);
}

TEST(Life, life13) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	assert(test.live_cells() != 25);
}

TEST(Life, life14) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[1][1]._alive = false;

	assert(test._grid[1][1]._alive != true);
}

TEST(Life, life15) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[0][0]._alive = false;

	assert(test._grid[0][0]._alive == false);
}

TEST(Life, life16) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[1][1]._alive = false;

	assert(test._grid[1][1]._alive != true);
}

TEST(Life, life17) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[1][1].inc_age();

	assert(test._grid[1][1]._age != 5);
}

TEST(Life, life18) {
	Life<FredkinCell> test;

	for(int i = 0; i < 5; ++i) {
		test._grid.resize(5);
		for(int j = 0; j < 5; ++j) {
			test._grid[i].resize(5);
		}
	}
	test._grid[1][1].inc_age();

	assert(test._grid[1][1]._age == 1);
}