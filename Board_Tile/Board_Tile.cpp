#include "Board_Tile.h"

Board_Tile::Board_Tile(const std::string& init, const std::string& g)
{
    this->config = init;
    this->goal = g;
    this->movesFromStart = 0;
    this->moves = "";
}

Board_Tile::Board_Tile(const std::string& init, const std::string& g, int moveCount, std::string m)
{
    this->config = init;
    this->goal = g;
    this->movesFromStart = moveCount;
    this->moves += m;
}

/**
* @returns a list of Board_Tile objects (at most 4) that ae one move ahead of the current Board_Tile
*/
std::list<Board_Tile> Board_Tile::nextConfigs()
{
    // list to hold the new possible Board_Tile configs
    std::list <Board_Tile> possibleMoves;

    /*
    * check all possible moves and create a
    * new Board_Tile from those possible moves
    *
    * the moving tile 0 can move up, down, left, or right
    * as long as there is a space in that direction.
    *
    * using the index of where the 0 tile is in the
    * string we can determind the possible moves
    *
    * UP = -3
    * DOWN = +3
    * LEFT = -1
    * RIGHT = +1
    */
    // get the index of the 0 tile
    int indx = this->find0();
    std::string tempConfig = this->config;
    int moveCount = this->movesFromStart + 1;
    std::string m = this->moves;

    if (indx >= 3) // the tile can move up
    {
        std::swap(tempConfig[indx], tempConfig[indx -3]);
        Board_Tile tempBoardUP(tempConfig, this->getGoalConfig(), moveCount, m + "U");
        possibleMoves.push_back(tempBoardUP);
    }

    tempConfig = this->config;
    if (indx <= 5) // the tile can move down
    {
        std::swap(tempConfig[indx], tempConfig[indx +3]);
        Board_Tile tempBoardDOWN(tempConfig, this->getGoalConfig(), moveCount, m + "D");
        possibleMoves.push_back(tempBoardDOWN);
    }

    tempConfig = this->config;
    if ((indx % 3) != 0) // the tile can move left
    {
        std::swap(tempConfig[indx], tempConfig[indx -1]);
        Board_Tile tempBoardLEFT(tempConfig, this->getGoalConfig(), moveCount, m + "L");
        possibleMoves.push_back(tempBoardLEFT);
    }

    tempConfig = this->config;
    if ((indx % 3) != 2) // the tile can move right
    {
        std::swap(tempConfig[indx], tempConfig[indx +1]);
        Board_Tile tempBoardRIGHT(tempConfig, this->getGoalConfig(), moveCount, m + "R");
        possibleMoves.push_back(tempBoardRIGHT);
    }

    return possibleMoves;
}

/**
* @returns the number of moves made to reach current config from initial
*/
int Board_Tile::numMoves() const
{
    return movesFromStart;
}

/**
* @returns the Manhattan distance of this Board_Tile
*/
int Board_Tile::Manhattan_Distance() const
{
    int md = 0;
    if (this->config == this->goal) {
        return 0;
    }

    char actual[3][3] = {{this->config[0], this->config.at(1), this->config.at(2)}, {this->config.at(3), this->config.at(4), this->config.at(5)}, {this->config.at(6), this->config.at(7), this->config.at(8)}};
    char goal[3][3] = {{this->goal[0], this->goal[1], this->goal[2]}, {this->goal.at(3), this->goal.at(4), this->goal.at(5)}, {this->goal.at(6), this->goal.at(7), this->goal.at(8)}};

    int currentSpot = -1;
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){

            currentSpot = (int)actual[x][y] - 48; // for each number in the actual config. we must find where it goes
            if (currentSpot != 0) // we do not include 0 in our Manhattan Distance calculation
                for (int x2 = 0; x2 < 3; x2++){
                    for (int y2 = 0; y2 < 3; y2++){
                        if (goal[x2][y2] == actual[x][y]) // we have found where currentSpot value is supposed to go
                        {
                            md += abs(x - x2) + abs(y - y2);
                        }
                    }
                }
            }
        }
     return md;
}

int Board_Tile::find0()
{
    for (unsigned int i = 0; i < config.length(); i++)
    {
        if (config[i] == '0')
            return i;
    }
    return -1;
}

std::string Board_Tile::getConfig() const
{
    return this->config;
}

std::string Board_Tile::getGoalConfig() const
{
    return this->goal;
}

std::string Board_Tile::getMoves() const
{
    return this->moves;
}

bool Board_Tile::operator<(const Board_Tile& b)
{
    return (this->Manhattan_Distance() + this->numMoves()) < (b.Manhattan_Distance() + b.numMoves());
}

bool Board_Tile::operator!=(const Board_Tile& b)
{
    return this->getConfig() != b.getConfig();
}

bool Board_Tile::operator()(const Board_Tile& a, const Board_Tile& b)
{
    return (a.Manhattan_Distance() + a.numMoves()) > (b.Manhattan_Distance() + b.numMoves());
}
