// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ RunLife.c++ -o RunLife
    % valgrind RunLife > RunLife.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    ofstream ofile;
    ofile.open("RunLife.out");

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        //cout << "*** Life<ConwayCell> 109x69 ***" << endl;
        /*
        read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */
        ifstream ifile("RunLifeConway.in");
        ofile << "*** Life<ConwayCell> 109x69 ***" << endl;

        Life<ConwayCell> life;
        life.store_cells(ifile);

        life.print(ofile, 0);
        life.simulate(283, 10, ofile);
        life.print(ofile, 283);

        life.simulate(40, 0, ofile);
        life.print(ofile, 323);

        life.simulate(2177, 0, ofile);
        life.print(ofile, 2500);
        
        /*
        Simulate 16 moves.
        Print 10 grids
        Print final gird
								*/
        
        ofile << "*** Life<ConwayCell> 15x15 ***" << endl;
        Life<ConwayCell> life2;
        life2.store_cells(ifile);
        
        life2.print(ofile, 0);
        life2.simulate(16, 10, ofile);
        life2.print(ofile, 16);
        
        /*
        psteiner
        */
        ofile << "*** psteiner Life<ConwayCell> 37x58 ***" << endl;
        Life<ConwayCell> life3;
        life3.store_cells(ifile);
        
        life3.print(ofile, 0);
        life3.simulate(16, 16, ofile);
        life3.print(ofile, 16);
        
        life3.simulate(14, 0, ofile);
        life3.print(ofile, 30);
        
        life3.simulate(30, 0, ofile);
        life3.print(ofile, 60);
        
        life3.simulate(30, 0, ofile);
        life3.print(ofile, 90);
        
        life3.simulate(30, 0, ofile);
        life3.print(ofile, 120);
        
        /*
        pjruiz15
        */
        ofile << "*** pjruiz15 Life<ConwayCell> 42x31 ***" << endl;
        Life<ConwayCell> life4;
        life4.store_cells(ifile);
        
        life4.print(ofile, 0);
        life4.simulate(5, 5, ofile);
        life4.print(ofile, 5);
        
        
        /*
        swilken
        */
        ofile << "*** swilken Life<ConwayCell> 9x5 ***" << endl;
        Life<ConwayCell> life5;
        life5.store_cells(ifile);
        
        life5.print(ofile, 0);
        life5.simulate(5, 5, ofile);
        life5.print(ofile, 5);
        
        ifile.close();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream ifile("RunLifeFredkin.in");
        ofile << "*** Life<FredkinCell> 20x20 ***" << endl;

        Life<FredkinCell> life;
        life.store_cells(ifile);
        
        life.print(ofile, 0);
        life.simulate(5, 6, ofile);
        
        
        /*
        Simulate 8 moves.
        Print 5 grids
        Print final gird
								*/

        ofile << "*** Life<FredkinCell> 30x20 ***" << endl;

        Life<FredkinCell> life2;
        life2.store_cells(ifile);
        
        life2.print(ofile, 0);
        life2.simulate(8, 5, ofile);
        life2.print(ofile, 8);


        /*
        pratik47
								*/
        ofile << "*** pratik47 Life<FredkinCell> 40x20 ***" << endl;
        
        Life<FredkinCell> life3;
        life3.store_cells(ifile);
        
        life3.print(ofile, 0);
        life3.simulate(5, 5, ofile);
        life3.print(ofile, 5);
        
        
        /*
        pratik47
								*/
        ofile << "*** pratik47 Life<FredkinCell> 26x26 ***" << endl;
        
        Life<FredkinCell> life4;
        life4.store_cells(ifile);
        
        life4.print(ofile, 0);
        life4.simulate(5, 5, ofile);
        life4.print(ofile, 5);
        
        ifile.close();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        //cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream ifile("RunLifeCell.in");
        ofile << "*** Life<Cell> 20x20 ***" << endl;

        Life<Cell> life;
        life.store_cells(ifile);
        life.print(ofile, 0);
        life.simulate(5, 6, ofile);
        
        
        /*
        Simulate 30 moves.
        Print 7 grids
        Print final gird
								*/

        ofile << "*** Life<Cell> 40x40 ***" << endl;
        
        Life<Cell> life2;
        life2.store_cells(ifile);
        
        life2.print(ofile, 0);
        life2.simulate(30, 7, ofile);
        life2.print(ofile, 30);
        
        /*
        ryan76
        */
        ofile << "*** ryan76 Life<Cell> 10x8 ***" << endl;
        
        Life<FredkinCell> life3;
        life3.store_cells(ifile);
        
        life3.print(ofile, 0);
        life3.simulate(5, 5, ofile);
        life3.print(ofile, 5);
        ifile.close();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    ofile.close();

    return 0;}

