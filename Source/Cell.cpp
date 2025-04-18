#include "../Header/Cell.h"

Cell::Cell() : isMine(false), isRevealed(false), isFlagged(false), adjacentMines(0) {}

bool Cell::hasMine() const {
    return isMine;
}

bool Cell::isRevealedCell() const {
    return isRevealed;
}

bool Cell::isFlaggedCell() const {
    return isFlagged;
}

int Cell::getAdjacentMines() const {
    return adjacentMines;
}

void Cell::setMine() {
    isMine = true;
}

void Cell::reveal() {
    isRevealed = true;
}

void Cell::toggleFlag() {
    if (!isRevealed)
        isFlagged = !isFlagged;
}

void Cell::setAdjacentMines(int count) {
    adjacentMines = count;
}
