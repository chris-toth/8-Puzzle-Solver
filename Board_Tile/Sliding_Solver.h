#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

#include <bits/stdc++.h> // priority_queue
#include "Board_Tile.h"
#include <vector>

class Sliding_Solver {
public:
    Sliding_Solver() {};
    Sliding_Solver(Board_Tile b);

    /**
    * Solves the puzzle using A* search
    */
    void Solve_Puzzle();


private:
    /**
    * @returns true if the board_tile config is found in the vector of visited configs
    */
    bool isVisited(Board_Tile b);

    void copyPrint();

    // minHeap of Board_Tile objects OPEN LIST
    std::priority_queue <Board_Tile, std::vector<Board_Tile>, Board_Tile> tileQueue;

    // vector of Board_Tile objects CLOSED LIST
    std::vector<Board_Tile> visitedBoards;

    // the board start
    Board_Tile board;
};

#endif // SLIDING_SOLVER_H
