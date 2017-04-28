#file = open("output.txt","w")
import random
#RANDOM GENERATION FUNCTIONS

import random, copy

sample  = [ [3,4,1,2,9,7,6,8,5],
            [2,5,6,8,3,4,9,7,1],
            [9,8,7,1,5,6,3,2,4],
            [1,9,2,6,7,5,8,4,3],
            [8,7,5,4,2,3,1,9,6],
            [6,3,4,9,1,8,2,5,7],
            [5,6,3,7,8,9,4,1,2],
            [4,1,9,5,6,2,7,3,8],
            [7,2,8,3,4,1,5,6,9] ]
            
"""
Randomly arrange numbers in a grid while making all rows, columns and
squares (sub-grids) contain the numbers 1 through 9.
"""
def construct_puzzle_solution():
    # Loop until we're able to fill all 81 cells with numbers, while
    # satisfying the constraints above.
    while True:
        try:
            puzzle  = [[0]*9 for i in range(9)] # start with blank puzzle
            rows    = [set(range(1,10)) for i in range(9)] # set of available
            columns = [set(range(1,10)) for i in range(9)] #   numbers for each
            squares = [set(range(1,10)) for i in range(9)] #   row, column and square
            for i in range(9):
                for j in range(9):
                    # pick a number for cell (i,j) from the set of remaining available numbers
                    choices = rows[i].intersection(columns[j]).intersection(squares[(i//3)*3 + j//3])
                    choice  = random.choice(list(choices))
        
                    puzzle[i][j] = choice
        
                    rows[i].discard(choice)
                    columns[j].discard(choice)
                    squares[(i//3)*3 + j//3].discard(choice)

            # success! every cell is filled.
            return puzzle
            
        except IndexError:
            # if there is an IndexError, we have worked ourselves in a corner (we just start over)
            pass

"""
Randomly pluck out cells (numbers) from the solved puzzle grid, ensuring that any
plucked number can still be deduced from the remaining cells.

For deduction to be possible, each other cell in the plucked number's row, column,
or square must not be able to contain that number. """
def pluck(puzzle, n=0):

    """
    Answers the question: can the cell (i,j) in the puzzle "puz" contain the number
    in cell "c"? """
    def canBeA(puz, i, j, c):
        v = puz[c//9][c%9]
        if puz[i][j] == v: return True
        if puz[i][j] in range(1,10): return False
            
        for m in range(9): # test row, col, square
            # if not the cell itself, and the mth cell of the group contains the value v, then "no"
            if not (m==c//9 and j==c%9) and puz[m][j] == v: return False
            if not (i==c//9 and m==c%9) and puz[i][m] == v: return False
            if not ((i//3)*3 + m//3==c//9 and (j//3)*3 + m%3==c%9) and puz[(i//3)*3 + m//3][(j//3)*3 + m%3] == v:
                return False

        return True


    """
    starts with a set of all 81 cells, and tries to remove one (randomly) at a time
    but not before checking that the cell can still be deduced from the remaining cells. """
    cells     = set(range(81))
    cellsleft = cells.copy()
    while len(cells) > n and len(cellsleft):
        cell = random.choice(list(cellsleft)) # choose a cell from ones we haven't tried
        cellsleft.discard(cell) # record that we are trying this cell

        # row, col and square record whether another cell in those groups could also take
        # on the value we are trying to pluck. (If another cell can, then we can't use the
        # group to deduce this value.) If all three groups are True, then we cannot pluck
        # this cell and must try another one.
        row = col = square = False

        for i in range(9):
            if i != cell//9:
                if canBeA(puzzle, i, cell%9, cell): row = True
            if i != cell%9:
                if canBeA(puzzle, cell//9, i, cell): col = True
            if not (((cell//9)//3)*3 + i//3 == cell//9 and ((cell//9)%3)*3 + i%3 == cell%9):
                if canBeA(puzzle, ((cell//9)//3)*3 + i//3, ((cell//9)%3)*3 + i%3, cell): square = True

        if row and col and square:
            continue # could not pluck this cell, try again.
        else:
            # this is a pluckable cell!
            puzzle[cell//9][cell%9] = 0 # 0 denotes a blank cell
            cells.discard(cell) # remove from the set of visible cells (pluck it)
            # we don't need to reset "cellsleft" because if a cell was not pluckable
            # earlier, then it will still not be pluckable now (with less information
            # on the board).

    # This is the puzzle we found.
    return (puzzle, len(cells))
    
def run(n = 28, iter=100):
    all_results = {}
    print ("Constructing a sudoku puzzle.")
    print ("* creating the solution...")
    a_puzzle_solution = construct_puzzle_solution()

    print ("* constructing a puzzle...")
    for i in range(iter):
        puzzle = copy.deepcopy(a_puzzle_solution)
        (result, number_of_cells) = pluck(puzzle, n)
        all_results.setdefault(number_of_cells, []).append(result)
        if number_of_cells <= n: break

    return all_results

def best(set_of_puzzles):
    # Could run some evaluation function here. For now just pick
    # the one with the fewest "givens".
    return set_of_puzzles[min(set_of_puzzles.keys())][0]

""" Controls starts here """
#results = run(n=0)       # find puzzles with as few givens as possible.
#puzzle  = best(results)  # use the best one of those puzzles.
#printBoard(puzzle)          # display that puzzle.


#ENG GENERATION FUNCTIONS

# function to print the board on to the console
def printBoard(board):
    print("*********************")
    for x in range(0, 9):
        if x == 3 or x == 6:
            print("*********************")
        for y in range(0, 9):
            if y == 3 or y == 6:
                print("*", end=" ")
            print(board[x][y], end=" ")
        print()
    print("*********************")
    
# function to check if the board is full or not
# returns true if it is full and false if it isn't
# it works on the fact that if it finds at least one 
# zero in the board it returns false
def isFull(board):
    for x in range(0, 9):
        for y in range (0, 9):
            if board[x][y] == 0:
                return False
    return True
    
# function to find all of the possible numbers
# which can be put at the specifies location by
# checking the horizontal and vertical and the 
# three by three square in which the numbers are
# housed
def possibleEntries(board, i, j):
    
    possibilityArray = {}
    
    for x in range (1, 10):
        possibilityArray[x] = 0
    
    #For horizontal entries
    for y in range (0, 9):
        if not board[i][y] == 0: 
            possibilityArray[board[i][y]] = 1
     
    #For vertical entries
    for x in range (0, 9):
        if not board[x][j] == 0: 
            possibilityArray[board[x][j]] = 1
            
    #For squares of three x three
    k = 0
    l = 0
    if i >= 0 and i <= 2:
        k = 0
    elif i >= 3 and i <= 5:
        k = 3
    else:
        k = 6
    if j >= 0 and j <= 2:
        l = 0
    elif j >= 3 and j <= 5:
        l = 3
    else:
        l = 6
    for x in range (k, k + 3):
        for y in range (l, l + 3):
            if not board[x][y] == 0:
                possibilityArray[board[x][y]] = 1          
    
    for x in range (1, 10):
        if possibilityArray[x] == 0:
            possibilityArray[x] = x
        else:
            possibilityArray[x] = 0
    
    return possibilityArray

# recursive function which solved the board and 
# prints it. 
def sudokuSolver(board):
    
    i = 0
    j = 0
    
    possiblities = {}
    
    # if board is full, there is no need to solve it any further
    if isFull(board):
        print("Board Solved Successfully!")
        printBoard(board)
        return
    else:
        # find the first vacant spot
        for x in range (0, 9):
            for y in range (0, 9):
                if board[x][y] == 0:
                    i = x
                    j = y
                    break
            else:
                continue
            break
        
        # get all the possibilities for i,j
        possiblities = possibleEntries(board, i, j)
        
        # go through all the possibilities and call the the function
        # again and again
        for x in range (1, 10):
            if not possiblities[x] == 0:
                board[i][j] = possiblities[x]
                #file.write(printFileBoard(board))
                sudokuSolver(board)
        # backtrack
        board[i][j] = 0
        

        
def main():
    #SudokuBoard = [[0 for x in range(9)] for x in range(9)]

    results = run(n=0)       # find puzzles with as few givens as possible.
    SudokuBoard  = best(results) 
    printBoard(SudokuBoard)
    sudokuSolver(SudokuBoard)
    #file.close()
    
if __name__ == "__main__":
    main()
