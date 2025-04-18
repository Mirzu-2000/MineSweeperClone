#include "../Header/Game.h"
#include <iostream>

int main() {
    int size;

    std::cout << "===== Minesweeper Setup =====\n";
    do {
        std::cout << "Enter grid size (n x n), minimum 9: ";
        std::cin >> size;
        if (size < 9)
            std::cout << "Grid size must be at least 9.\n";
    } while (size < 9);

    int totalCells = size * size;
    int mines = static_cast<int>(totalCells * 0.16); // 16% mine density

    std::cout << "Initializing " << size << "x" << size << " grid with " << mines << " mines.\n";

    Game game(size, mines);
    game.start();

    return 0;
}
