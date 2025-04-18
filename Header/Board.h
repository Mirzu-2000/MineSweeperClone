#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Header/Cell.h"

class Board {
private:
    int size;
    int mineCount;
    bool firstMoveDone;
    std::vector<std::vector<Cell>> grid;

    void placeMines(int firstRow, int firstCol);
    void calculateAdjacents();
    bool isValid(int row, int col) const;
    int countAdjacentMines(int row, int col) const;

public:
    Board(int n, int mines);

    void revealCell(int row, int col);
    void toggleFlag(int row, int col);
    bool isMineAt(int row, int col) const;
    bool isRevealed(int row, int col) const;
    bool isFlagged(int row, int col) const;
    int getAdjacentMines(int row, int col) const;
    void display(bool revealAll = false) const;
    bool isComplete() const;
};

#endif
