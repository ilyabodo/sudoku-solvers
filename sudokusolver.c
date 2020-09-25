#include <stdio.h>



void print_sudoku(int arr[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int * find_empty_location(int arr[9][9]) {
  static int result[2];
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++) {
      if (arr[i][j] == 0) {
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }
  return NULL;
}




int is_valid(int arr[9][9], int row, int col, int x) {
  printf("%d\n", x);
  // Checks if the number x is unique in the row
  for (int i = 0; i < 9; i++) {
    if (arr[row][i] == x) {
      return 0;
    }
  }

  for (int j = 0; j < 9; j++) {
    if (arr[j][col] == x) {
      return 0;
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (arr[i + row - row%3][j + col - col%3] == x) {
        return 0;
      }
    }
  }
  return 1;

}

int solve_sudoku(int arr[9][9]) {
  int *next_loc = find_empty_location(arr);
  

  if (next_loc == NULL) {
    return 1;
  }

  int row = next_loc[0];
  int col = next_loc[1];
  printf("%d\n", row);
  for (int x = 1; x < 10; x++) {
    if(is_valid(arr, row, col, x) == 1) {
      arr[row][col] = x;

      if (solve_sudoku(arr) == 1) {
        return 1;
      }
      arr[row][col] = 0;
    }
  }
  return 0;
}

int main(void) {

  int grid[9][9] = {{0, 2, 0, 0, 0, 5, 0, 0, 0},
                    {0, 1, 5, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 8, 7, 0, 3},
                    {0, 5, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 9, 7, 0, 0, 0, 1, 0},
                    {0, 0, 0, 3, 0, 0, 0, 4, 6},
                    {0, 0, 0, 0, 8, 0, 0, 0, 1},
                    {7, 0, 0, 9, 3, 0, 0, 6, 0},
                    {0, 0, 0, 0, 0, 0, 4, 0, 8}};
  solve_sudoku(grid);
  print_sudoku(grid);            
  return 0;
}