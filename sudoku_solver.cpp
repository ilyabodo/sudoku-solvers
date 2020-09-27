#include <iostream>

using namespace std;

bool solve_sudoku(int arr[9][9]);
bool is_valid(int arr[9][9], int row, int col, int x);
void find_empty_location(int arr[9][9], int out[2]);
void print_sudoku(int arr[9][9]);

int main() {
    
    int grid[9][9] = {{0, 2, 0, 0, 0, 5, 0, 0, 0},
                      {0, 1, 5, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 8, 7, 0, 3},
                      {0, 5, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 9, 7, 0, 0, 0, 1, 0},
                      {0, 0, 0, 3, 0, 0, 0, 4, 6},
                      {0, 0, 0, 0, 8, 0, 0, 0, 1},
                      {7, 0, 0, 9, 3, 0, 0, 6, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 8}};
    
    if (solve_sudoku(grid)) {
        cout << "Solved sudoku:\n";
        print_sudoku(grid);
    }
    else
        cout << "No solution found.";
}

// Main function that solves the sudoku using backtracking
bool solve_sudoku(int arr[9][9]) {
    int next_loc[2] = {-1, -1};
    find_empty_location(arr, next_loc);
    if (next_loc[0] == -1) { // if there is no next location, then the algorithm is done
        return true;
    }
    int row = next_loc[0];
    int col = next_loc[1];
    
    // loops through the digits 1-9 for a given location
    for (int x = 1; x < 10; x++) {
        if(is_valid(arr, row, col, x) == 1) { // checks if the digit is valid at this row,column
            arr[row][col] = x;

            // Recursivly calls solver until no digit works in a location, then causes backtrack
            if (solve_sudoku(arr)) {
                return true;
            }
            // if run fails, reset to 0 then will backtrack
            arr[row][col] = 0;
        }
    }
    //triggers backtracking
    return false;
}

// Checks if X is allowed to be placed in the grid at row,col
bool is_valid(int arr[9][9], int row, int col, int x) {
    
    // Checks if the number x is unique in the row
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == x) {
            return false;
        }
    } 

    // Checks if the number x is unique in the column   
    for (int j = 0; j < 9; j++) {
        if (arr[j][col] == x) {
            return false;
        }
    }   

    // Checks if the number x is unique in it's square
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i + row - row%3][j + col - col%3] == x) {
                return false;
            }
        }
    } 

    // Returns true if x is unique in row, column, and the square
    return true;
}

// Finds the next location in the grid that doesn't have a digit (0)
void find_empty_location(int arr[9][9], int out[2]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                out[0] = i;
                out[1] = j;
                return;
            }
        }
    }
}

// Prints the supplied sudoku grid to the console with spaces between the numbers
void print_sudoku(int arr[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << to_string(arr[i][j]) + " ";
        }
        cout << "\n";
    }
}