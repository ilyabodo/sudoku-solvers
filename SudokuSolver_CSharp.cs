using System;
public class SudokuSolver
{
    public static void Main(string[] args)
    {
        // Input unsolved sudoku grid
        int[,] grid = new int[9,9] {{0, 2, 0, 0, 0, 5, 0, 0, 0},
                                    {0, 1, 5, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 8, 7, 0, 3},
                                    {0, 5, 1, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 9, 7, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 3, 0, 0, 0, 4, 6},
                                    {0, 0, 0, 0, 8, 0, 0, 0, 1},
                                    {7, 0, 0, 9, 3, 0, 0, 6, 0},
                                    {0, 0, 0, 0, 0, 0, 4, 0, 8}};

        if (SolveSudoku(grid))
        {
            PrintSudoku(grid);
        }
        else {
            Console.WriteLine("No solution found.");
        }
        
    }

    // Main method that solves the sudoku using backtracking
    private static Boolean SolveSudoku(int[,] arr)
    {
        Tuple<int, int> newLoc = FindEmptyLocation(arr);

        //If null, then sudoku has been solved
        if (newLoc == null)
        {
            return true;
        }
        int row  = newLoc.Item1;
        int col = newLoc.Item2;

        //Loops through each digit 1-9
        for (int x = 1; x < 10; x++) 
        {
            if (IsValid(arr, row, col, x)) // if x is valid in current location
            {
                arr[row,col] = x;

                // Recursivly calls solver until IsValid fails, then backtracking starts
                if (SolveSudoku(arr)) 
                {
                    return true;
                }
                // if run fails, reset to 0 then backtracks
                arr[row, col] = 0;
            }
        }
        // Returning false triggers backtrack
        return false;
    }

    // Prints the supplied sudoku grid to the console with spaces between the numbers
    private static void PrintSudoku(int[,] arr) {
        for (int i = 0; i < 9; i++) 
        {
            string row = "";
            for (int j = 0; j < 9; j++) 
            {
                row = row + arr[i,j] + " "; // Appends each element to the row
            }
            Console.WriteLine(row);
        }
    }

    // Checks if X is allowed to be placed in the grid at row,col
    private static Boolean IsValid(int[,] arr, int row, int col, int x)
    {
        // Checks if the number x is unique in the row
        for (int i = 0; i < 9; i++)
        {
            if (arr[row,i] == x) return false;
        }

        // Checks if the number x is unique in the column
        for (int i = 0; i < 9; i++)
        {
            if (arr[i,col] == x) return false;
        }

        // Checks if the number x is unique in it's square
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i + row - row%3, j + col - col%3] == x) 
                {
                    return false;
                }
            }
        }
        // Returns true if x is unique in row, column, and the square
        return true;
    }

    // Method finds the next location in the grid that doesn't have a number
    private static Tuple<int, int> FindEmptyLocation(int[,] arr)
    {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                if (arr[i,j] == 0) {
                    return Tuple.Create(i, j);
                }
            }
        }
        // Returns null if there is no more empty locations
        return null;
    }
}

