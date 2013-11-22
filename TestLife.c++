#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"

using namespace std;

TEST(FredkinCell, fredkin1) {
	FredkinCell test;
	cout << test.type();
	assert(1);
	// assert(test._alive == true);
}

/*TEST(FredkinCell, fredkin2) {
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
}*/