#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
private:
    Board* board;
    int size;
    int mineCount;
    bool gameOver;

    void printInstructions() const;
    void gameLoop();
    void handleInput();

public:
    Game(int size, int mines);
    ~Game();
    void start();
};

#endif
