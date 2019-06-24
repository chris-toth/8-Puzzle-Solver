#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(Board_Tile b)
{
    this->board = b;
}

void Sliding_Solver::Solve_Puzzle()
{
    // push the current board to get started
    tileQueue.push(board);

    // output some information
    std::cout << "\n" << board.getConfig() << "       " << board.getGoalConfig();

    // until the board is completed do
    while (!tileQueue.empty())
    {
        // start by getting the board from the top of the queue
        Board_Tile current = tileQueue.top();
        tileQueue.pop();

/** Advice courtesey of Stephen Graham June 2019 */
/* start Debug code to watch the priority queue a bit. smg /
        // look at what happens to the MD and the size of your priority queue...
//        std::cout << "\n" << current.getConfig() << " MD=" << current.Manhattan_Distance() << " numMoves=" << current.numMoves() << " pqSize=" << tileQueue.size(); //smg
/ end Debug code to watch the priority queue a bit. smg */

        // check the current board to see if we are done.
        if (current.Manhattan_Distance() == 0) {
            std::cout << "         " << current.numMoves() << "           " << current.getMoves() << "\n\n";

//            while (!tileQueue.empty())
//                tileQueue.pop();

            break;
        }

        // collect next configs from the current board
        std::list<Board_Tile> next = current.nextConfigs();

        // after expanding current config. add current board to closed list
        visitedBoards.push_back(current);

        // add new configs to the open list
        for (std::list<Board_Tile>::iterator nextIt = next.begin(); nextIt != next.end(); nextIt++)
        {
            Board_Tile addNext = *nextIt;

            // screen for previously traversed boards.
            if (!isVisited(addNext))
                tileQueue.push(addNext); // the next board has not been visited. add it to the list
        }
//        copyPrint();
    }
}

/*
* a function to scan the visited configurations so we dont add one we have visited
*/
bool Sliding_Solver::isVisited(Board_Tile b)
{
    for (std::vector<Board_Tile>::iterator v = visitedBoards.begin(); v != visitedBoards.end(); v++)
    {
        Board_Tile temp = *v;
        if (b.getConfig() == temp.getConfig())
        {
            return true;
        }
    }
    return false;
}

/*
* A helper funtion to debug and watch the puzzle solve
*/
void Sliding_Solver::copyPrint()
{
    std::priority_queue <Board_Tile, std::vector<Board_Tile>, Board_Tile> copyQueue = tileQueue;
    Board_Tile temp;
    std::cout << "\nStart of priority queue:\n";
    while (copyQueue.size() > 0) {
        temp = copyQueue.top();
        copyQueue.pop();
        std::cout << "Config: " << temp.getConfig() << " MD: " << temp.Manhattan_Distance() << " Moves: " << temp.getMoves() << "\n";
    }
    std::cout << "End of PQ...\n";
}
