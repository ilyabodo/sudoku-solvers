public class SudokuSolver {
    public static void main(String[] args) {

        //Input sudoku grid
        int[][] grid = {{0, 2, 0, 0, 0, 5, 0, 0, 0},
                        {0, 1, 5, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 8, 7, 0, 3},
                        {0, 5, 1, 0, 0, 0, 0, 0, 0},
                        {0, 0, 9, 7, 0, 0, 0, 1, 0},
                        {0, 0, 0, 3, 0, 0, 0, 4, 6},
                        {0, 0, 0, 0, 8, 0, 0, 0, 1},
                        {7, 0, 0, 9, 3, 0, 0, 6, 0},
                        {0, 0, 0, 0, 0, 0, 4, 0, 8}};

        if(solveSudoku(grid)) {
            printSudoku(grid);
        }
        else {
            System.out.println("No solution");
        }
    }

    //Main method that solves the sudoku
    private static boolean solveSudoku(int[][] arr) {
        int[] newLoc = findEmptyLocation(arr);

        //If null, then sudoku has been solved
        if (newLoc == null) {
            return true;
        }

        int row = newLoc[0];
        int col = newLoc[1];

        for (int x = 1; x < 10; x++) {
            if (isValid(arr, row, col, x)) {
                arr[row][col] = x;

                if (solveSudoku(arr)) {
                    return true;
                }
                arr[row][col] = 0;
            }
        }
        return false;
    }

    private static void printSudoku(int[][] arr) {
        for (int i = 0; i < 9; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < 9; j++) {
                // Appends each element to the row
                row.append(arr[i][j]).append(" ");
            }
            System.out.println(row);
        }
    }

    private static boolean isValid(int[][] arr, int row, int col, int x) {

        // Checks if the number x is unique in the row
        for (int i = 0; i < 9; i++) {
            if (arr[row][i] == x) {return false;}
        }

        // Checks if the number x is unique in the column
        for (int i = 0; i < 9; i++) {
            if (arr[i][col] == x) {return false;}
        }

        // Checks if the number x is unique in it's square
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                if (arr[i + row - row%3][j + col - col%3] == x) {
                    return false;
                }
            }
        }
        // Returns true if x is unique in row, column, and the square
        return true;
    }

    // Method finds the next location in the grid that doesn't have a number
    private static int[] findEmptyLocation(int[][] arr) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                if (arr[i][j] == 0) {
                    return new int[]{i, j};
                }
            }
        }
        // Returns null if there is no more empty locations
        return null;
    }
}