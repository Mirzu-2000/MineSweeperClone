# Minesweeper Console Game

This is a **C++** implementation of a **Minesweeper** game in the console, designed with **Object-Oriented Programming (OOP)** principles and following **SOLID** design principles.

## Features
- Customizable grid size (minimum 9x9).
- Mines are randomly placed at **16%** of the total cells.
- User can reveal or flag cells.
- Clear console UI with updated board display after each move.
- Game ends on a mine hit (Game Over) or when all non-mine cells are revealed (Victory).

## Design Principles
- **OOP**: The game is modular, with distinct classes for handling different parts of the game (e.g., `Game`, `Board`, `Cell`).
- **SOLID**: The code follows the **Single Responsibility Principle (SRP)** and is open for extension and closed for modification (e.g., adding new features without changing core classes).

## Code Structure
- **`Game.h`** and **`Game.cpp`**: Manages the game flow and player interaction.
- **`Board.h`** and **`Board.cpp`**: Handles grid setup and mine placement.
- **`Cell.h`** and **`Cell.cpp`**: Represents each cell’s state (mine, revealed, flagged).

## Installation
1. Clone or download the repository.
2. Open in **Visual Studio** or any C++ IDE.
3. Build and run the project.

### Example:
