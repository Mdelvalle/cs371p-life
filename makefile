all:
	make Life.zip

clean:
	rm -f Life.log
	rm -f Life.zip
	rm -f RunLife
	rm -f RunLife.out

doc: Life.h
	doxygen Doxyfile

turnin-list:
	turnin --list reza cs371ppj5

turnin-submit: Life.zip
	turnin --submit reza cs371ppj5 Life.zip

turnin-verify:
	turnin --verify reza cs371ppj5

Life.log:
	git log > Life.log

Life.zip: makefile                                          \
          AbstractCell.c++ AbstractCell.h                   \
          Handle.h Cell.c++ Cell.h                          \
          ConwayCell.c++ ConwayCell.h                       \
          FredkinCell.c++ FredkinCell.h                     \
          Life.h Life.log Life.pdf                          \
          RunLifeConway.in RunLifeFredkin.in RunLifeCell.in \
          RunLife.c++ RunLife.out                           \
          TestLife.c++ TestLife.out
	zip -r Life.zip                                          \
           html/ makefile                                    \
           AbstractCell.c++ AbstractCell.h                   \
           Handle.h Cell.c++ Cell.h                          \
           ConwayCell.c++ ConwayCell.h                       \
           FredkinCell.c++ FredkinCell.h                     \
           Life.h Life.log Life.pdf                          \
           RunLifeConway.in RunLifeFredkin.in RunLifeCell.in \
           RunLife.c++ RunLife.out                           \
           TestLife.c++ TestLife.out

RunLife: Life.h Life.c++ RunLife.c++
	g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ RunLife.c++ -o RunLife -lgtest -lpthread -lgtest_main

RunLife.out: RunLife
	valgrind ./RunLife > RunLife.out

TestLife: Life.h Life.c++ TestLife.c++
	g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

TestLife.out: TestLife
	valgrind ./TestLife > TestLife.out

