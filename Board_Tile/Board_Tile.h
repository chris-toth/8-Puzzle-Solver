#ifndef BOARD_TILE_H
#define BOARD_TILE_H

#include <string>
#include <list> // nextConfigs
#include <stdlib.h> // abs()

class Board_Tile {

public:
    Board_Tile() {};
    Board_Tile(const std::string& init, const std::string& g);
    Board_Tile(const std::string& init, const std::string& g, int moveCount, std::string m);

    /**
    * @returns a list of Board_Tile objects (at most 4) that are one move ahead of the current Board_Tile
    */
    std::list<Board_Tile> nextConfigs();

    /**
    * @returns the number of moves made to reach current config from initial
    */
    int numMoves() const;

    /**
    * @returns the Manhattan distance of this Board_Tile
    */
    int Manhattan_Distance() const;

    /**
    * @returns the index of the movable tile (0) in the string
    */
    int find0();

    /**
    * @returns the current config of the board
    */
    std::string getConfig() const;

    /**
    * @returns the goal config of the board
    */
    std::string getGoalConfig() const;

    /**
    * @returns the string of moves made
    */
    std::string getMoves() const;

    // operators used to compare board tiles
    bool operator<(const Board_Tile& b);
    bool operator!=(const Board_Tile& b);
    bool operator()(const Board_Tile& a, const Board_Tile& b);

private:
    // Initial starting config of the Board_Tile
    std::string config;

    // Goal configuration of this board
    std::string goal;

    // list of the moves made
    std::string moves;

    // Count of the moves made from initial config
    int movesFromStart;
};

#endif //BOARD_TILE
