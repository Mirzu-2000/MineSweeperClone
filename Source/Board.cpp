#include "../Header/Board.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

Board::Board(int n, int mines) : size(n), mineCount(mines), firstMoveDone(false) {
    grid.resize(size, std::vector<Cell>(size));
    srand(static_cast<unsigned int>(time(nullptr)));
}

bool Board::isValid(int row, int col) const {
    return row >= 0 && row < size && col >= 0 && col < size;
}

void Board::placeMines(int firstRow, int firstCol) {
    int placed = 0;
    while (placed < mineCount) {
        int r = rand() % size;
        int c = rand() % size;

        if ((r == firstRow && c == firstCol) || grid[r][c].hasMine()) continue;

        grid[r][c].setMine();
        placed++;
    }
    calculateAdjacents();
}

int Board::countAdjacentMines(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int r = row + dr;
            int c = col + dc;
            if (isValid(r, c) && grid[r][c].hasMine()) {
                count++;
            }
        }
    }
    return count;
}

void Board::calculateAdjacents() {
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            int count = countAdjacentMines(r, c);
            grid[r][c].setAdjacentMines(count);
        }
    }
}

void Board::revealCell(int row, int col) {
    if (!isValid(row, col) || grid[row][col].isRevealedCell() || grid[row][col].isFlaggedCell()) return;

    if (!firstMoveDone) {
        placeMines(row, col);
        firstMoveDone = true;
    }

    grid[row][col].reveal();

    if (grid[row][col].getAdjacentMines() == 0 && !grid[row][col].hasMine()) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr != 0 || dc != 0) {
                    revealCell(row + dr, col + dc);
                }
            }
        }
    }
}

void Board::toggleFlag(int row, int col) {
    if (isValid(row, col))
        grid[row][col].toggleFlag();
}

bool Board::isMineAt(int row, int col) const {
    return isValid(row, col) && grid[row][col].hasMine();
}

bool Board::isRevealed(int row, int col) const {
    return isValid(row, col) && grid[row][col].isRevealedCell();
}

bool Board::isFlagged(int row, int col) const {
    return isValid(row, col) && grid[row][col].isFlaggedCell();
}

int Board::getAdjacentMines(int row, int col) const {
    return isValid(row, col) ? grid[row][col].getAdjacentMines() : 0;
}

void Board::display(bool revealAll) const {
    std::cout << "   ";
    for (int c = 0; c < size; ++c)
        std::cout << std::setw(2) << c << " ";
    std::cout << "\n";

    for (int r = 0; r < size; ++r) {
        std::cout << std::setw(2) << r << " ";
        for (int c = 0; c < size; ++c) {
            const Cell& cell = grid[r][c];
            if (revealAll || cell.isRevealedCell()) {
                if (cell.hasMine())
                    std::cout << " * ";
                else if (cell.getAdjacentMines() > 0)
                    std::cout << " " << cell.getAdjacentMines() << " ";
                else
                    std::cout << " . ";
            }
            else if (cell.isFlaggedCell()) {
                std::cout << " F ";
            }
            else {
                std::cout << " # ";
            }
        }
        std::cout << "\n";
    }
}

bool Board::isComplete() const {
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            const Cell& cell = grid[r][c];
            if (!cell.hasMine() && !cell.isRevealedCell())
                return false;
        }
    }
    return true;
}
