#include <iostream>
using namespace std;

// Function to check if a digit can be placed at a given position
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    
    // Check if the number is already present in the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[9][9]) {
    int row, col;
    
    // Find the first empty cell (with value 0)
    bool isEmpty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    
    // If there are no empty cells, the puzzle is solved
    if (!isEmpty) {
        return true;
    }
    
    // Try placing a digit from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if the digit can be placed at the current position
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            // Recursively solve the puzzle
            if (solveSudoku(grid)) {
                return true;
            }
            
            // If placing the digit leads to an invalid solution, backtrack
            grid[row][col] = 0;
        }
    }
    
    // If no digit can be placed at the current position, return false
    return false;
}

// Function to display the solved Sudoku puzzle
// Function to display the solved Sudoku puzzle
void displaySudoku(int inputGrid[9][9], int outputGrid[9][9]) {
    cout << "Input Sudoku Puzzle:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << inputGrid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n-----------------\n\n";
    cout << "Solved Sudoku Puzzle:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << outputGrid[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int inputGrid[9][9];
    
    // Input the Sudoku puzzle from the user
    cout << "Enter the Sudoku puzzle (0 for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> inputGrid[i][j];
        }
    }
    
    int outputGrid[9][9];
    
    // Copy input grid to output grid for displaying later
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outputGrid[i][j] = inputGrid[i][j];
        }
    }
    
    // Solve the Sudoku puzzle
    if (solveSudoku(outputGrid)) {
        // Display the solved puzzle
        displaySudoku(inputGrid, outputGrid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }
    
    return 0;
}