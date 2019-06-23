#include <iostream>
#include "Board_Tile.h"
#include "Sliding_Solver.h"

int main() {

    Board_Tile board("123745086", "123456780");

    Board_Tile R("123745806", "123456780");
    Board_Tile U("123045786", "123456780");

    std::cout << "MD: " << board.Manhattan_Distance() << " EXPECTED: 4" << std::endl;
    std::cout << "\nMD: " << R.Manhattan_Distance() << " EXPECTED: 5" << std::endl;
    std::cout << "\nMD: " << U.Manhattan_Distance() << " EXPECTED: 3" << std::endl;


    std::cout << "\nStart Board  " << "  Goal Board  " << " Number of Moves " << " Solution" << std::endl;

    Sliding_Solver s(board);
    s.Solve_Puzzle();


    Board_Tile board2("436871052", "123456780");
    Sliding_Solver t(board2);
    t.Solve_Puzzle();

    std::cout << std::endl;
}
