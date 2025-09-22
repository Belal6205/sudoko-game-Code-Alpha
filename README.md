# Sudoku Game (C++)

A simple console-based Sudoku game implemented in C++. The game generates a random Sudoku puzzle and allows the user to play by entering numbers into the board.

## Features
- Randomly generates a simple Sudoku puzzle each time you play
- Console-based interface for easy interaction
- Input validation to prevent invalid moves
- Option to quit the game at any time

## How to Play
1. Run the executable or compile the code (see below).
2. The Sudoku board will be displayed with some cells filled and others empty (shown as ".").
3. Enter the row (0-8), column (0-8), and number (1-9) you want to place, separated by spaces.
4. If the move is valid, the number will be placed. If not, you'll be prompted to try again.
5. Enter -1 as the row to quit the game at any time.

## Compilation
To compile the project using g++:

```sh
g++ main.cpp -o sudoku
```

To run the game:

```sh
./sudoku
```
Or on Windows:
```sh
sudoku.exe
```

## File Structure
- `main.cpp` - Main source code for the Sudoku game
- `main.exe` / `bin/Debug/sudoko game Code Alpha.exe` - Compiled executable (may vary by build system)

## Requirements
- C++ compiler (e.g., g++, MinGW, Visual Studio)

## License
This project is for educational purposes.
