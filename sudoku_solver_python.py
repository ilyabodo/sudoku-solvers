grid = [[0, 2, 0, 0, 0, 5, 0, 0, 0],
		[0, 1, 5, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 8, 7, 0, 3],
		[0, 5, 1, 0, 0, 0, 0, 0, 0],
		[0, 0, 9, 7, 0, 0, 0, 1, 0],
		[0, 0, 0, 3, 0, 0, 0, 4, 6],
		[0, 0, 0, 0, 8, 0, 0, 0, 1],
		[7, 0, 0, 9, 3, 0, 0, 6, 0],
		[0, 0, 0, 0, 0, 0, 4, 0, 8]]

def solve_sudoku(arr): 

	# Assigns the next locations to row and col ints
	# If theres no empty locaions, then ends
	row, col = find_empty_location(arr)
	if(row == None):
		return True

	# Loops through digits 1 to 9
	for x in range(1, 10): 
		
		# checks if x is valid in current location
		if(is_valid(arr, row, col, x)): 
			  
			# make tentative assignment 
			arr[row][col]= x

			if(solve_sudoku(arr)): 
				return True

			# if run fails, reset to 0 then backtracks
			arr[row][col] = 0
			
	#triggers backtrack
	return False

#Checks if X is allowed to be placed in the grid at row,col
def is_valid(arr, row, col, x) -> bool:

	#Checks validity in the row
	for i in range(0, 9): 
		if (arr[row][i] == x): 
			return False

	#Checks validity in the column
	for i in range(0, 9): 
		if (arr[i][col] == x): 
			return False

	#Checks validity in the square
	for i in range(0, 3):
		for j in range(0, 3): 
			if (arr[i + row - row%3][j + col - col%3] == x):
				return False		
	#Returns true if valid in the row, column and square
	return True

def print_sudoku(arr):
	for i in range(0, 9):
		row = ''
		for j in range(0, 9):
			row += str(arr[i][j]) + ' '
		print(row)	

#Finds the next empty ("0") space and returns its location
def find_empty_location(arr): 
	for row in range(0, 9): 
		for col in range(0, 9): 
			if (arr[row][col] == 0): 
				return row, col
	# Returning None indicates no more empty locations and solver is done			
	return None, None



if solve_sudoku(grid):
	print_sudoku(grid)
else:
	print("No solution")	