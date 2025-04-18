#include <iostream>
#include "../Header/Board.h"

int main() {
    int size = 9;
    int mines = 10;
    Board board(size, mines);

    while (true) {
        board.display();
        int row, col;
        char action;
        std::cout << "Enter row col (and F to flag or R to reveal): ";
        std::cin >> row >> col >> action;

        if (action == 'F' || action == 'f') {
            board.toggleFlag(row, col);
        }
        else {
            board.revealCell(row, col);
            if (board.isMineAt(row, col) && board.isRevealed(row, col)) {
                std::cout << " Boom! You hit a mine!\n";
                board.display(true);
                break;
            }
        }

        if (board.isComplete()) {
            std::cout << " Congratulations! You cleared the board!\n";
            board.display(true);
            break;
        }
    }

    return 0;
}
