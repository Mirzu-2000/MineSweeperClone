#include <iostream>
#include "../Header/Cell.h"

int main() {
    Cell c;
    c.setMine();
    c.toggleFlag();
    c.setAdjacentMines(3);
    c.reveal();

    std::cout << "Mine: " << c.hasMine() << "\n";
    std::cout << "Flagged: " << c.isFlaggedCell() << "\n";
    std::cout << "Revealed: " << c.isRevealedCell() << "\n";
    std::cout << "Adjacent Mines: " << c.getAdjacentMines() << "\n";

    return 0;
}
