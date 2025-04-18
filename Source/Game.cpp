#include "../Header/Game.h"
#include <iostream>
#include <limits>

Game::Game(int size, int mines) : size(size), mineCount(mines), gameOver(false) {
    board = new Board(size, mines);
}

Game::~Game() {
    delete board;
}

void Game::printInstructions() const {
    std::cout << "===== Welcome to Text-Based Minesweeper! =====\n";
    std::cout << "Grid Size: " << size << " x " << size << "\n";
    std::cout << "Mines: " << mineCount << "\n\n";
    std::cout << "How to Play:\n";
    std::cout << " - Enter coordinates as: row column action\n";
    std::cout << "   Example: 3 5 R  ? reveals cell at (3,5)\n";
    std::cout << "   Example: 4 2 F  ? flags cell at (4,2)\n";
    std::cout << " - Symbols:\n";
    std::cout << "   # : Hidden Cell\n";
    std::cout << "   F : Flagged Cell (you suspect a mine)\n";
    std::cout << "   . : Revealed, no adjacent mines\n";
    std::cout << "   1-8 : Revealed, shows adjacent mine count\n";
    std::cout << "   * : Mine (appears only on loss or full reveal)\n";
    std::cout << " - First move is always safe (no mines!)\n";
    std::cout << " - Clear all safe cells to win!\n\n";
}

void Game::start() {
    printInstructions();
    gameLoop();
}

void Game::gameLoop() {
    while (!gameOver) {
        board->display();
        handleInput();

        if (board->isComplete()) {
            board->display(true);
            std::cout << " Congratulations, you cleared the board!\n";
            gameOver = true;
        }
    }
}

void Game::handleInput() {
    int row, col;
    char action;
    std::cout << "Enter your move (row col R/F): ";
    std::cin >> row >> col >> action;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
        return;
    }

    if (action == 'R' || action == 'r') {
        board->revealCell(row, col);
        if (board->isMineAt(row, col) && board->isRevealed(row, col)) {
            board->display(true);
            std::cout << " Boom! You hit a mine. Game over.\n";
            gameOver = true;
        }
    }
    else if (action == 'F' || action == 'f') {
        board->toggleFlag(row, col);
    }
    else {
        std::cout << "Invalid action. Use R (reveal) or F (flag).\n";
    }
}
