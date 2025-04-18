#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjacentMines;

public:
    Cell();

    bool hasMine() const;
    bool isRevealedCell() const;
    bool isFlaggedCell() const;
    int getAdjacentMines() const;

    void setMine();
    void reveal();
    void toggleFlag();
    void setAdjacentMines(int count);
};

#endif
