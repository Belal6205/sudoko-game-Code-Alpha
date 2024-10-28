#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Sudoku {
private:
    int board[9][9];

public:
    Sudoku() {
        // Initialize the board with zeros
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = 0;
            }
        }
        generatePuzzle();
    }

    void generatePuzzle() {
        // Randomly fill the board with a few numbers for a simple puzzle
        srand(static_cast<unsigned int>(time(0))); // Seed for randomness
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (rand() % 3 == 0) { // Randomly decide to fill a cell
                    int num = rand() % 9 + 1; // Random number from 1 to 9
                    if (isSafe(i, j, num)) {
                        board[i][j] = num;
                    }
                }
            }
        }
    }

    void displayBoard() {
        cout << "-------------------------\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == 0) {
                    cout << "| . ";
                } else {
                    cout << "| " << board[i][j] << " ";
                }
            }
            cout << "|\n-------------------------\n";
        }
    }

    bool isSafe(int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }
        // Check 3x3 box
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    void playGame() {
        int row, col, num;
        char choice;

        while (true) {
            cout << "\nCurrent Sudoku Board:\n";
            displayBoard();
            cout << "Enter row (0-8), column (0-8), and number (1-9) to place (or -1 to quit): ";
            cin >> row;
            if (row == -1) break; // Quit the game
            cin >> col >> num;

            if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9) {
                cout << "Invalid input! Please try again.\n";
                continue;
            }

            // Place the number on the board
            if (isSafe(row, col, num)) {
                board[row][col] = num;
            } else {
                cout << "Number cannot be placed here! Try again.\n";
            }

            cout << "Do you want to continue playing? (y/n): ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') break;
        }

        cout << "Thanks for playing!\n";
    }
};

int main() {
    Sudoku sudoku;
    sudoku.playGame();
    return 0;
}
