#include "sudoku.h"
/** There is Generation algorithm of our Sudoku puzzle, it is a simple generation using backtracking method ! */


/** Function which will check if the value exist on actual Row . */
bool existsRow(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int row, int value) {
	int col;
    for (col = 0; col < SizeOfPuzzle; col++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

/** Function which will check if the value exist on actual Column . */
bool existsCol(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int col, int value) {
	int row;
    for (row = 0; row < SizeOfPuzzle; row++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

/** Function which will check if the value exist on actual box . */
bool existsBox(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int boxRow, int boxCol, int value) {
	int row,col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (puzzle[row+boxRow][col+boxCol] == value) {
                return true;
            }
        }
    }
    return false;
}

/** Give permission to insert value in primary matrix ! */
bool legalAssign(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int row, int col, int value) {
    int x = boxLength(SizeOfPuzzle); /** Get size of box */

    return !existsRow(puzzle, row, value) && !existsCol(puzzle, col, value) && !existsBox(puzzle, row-row%x, col-col%x, value);
}


void randomGeneration(int puzzle[SizeOfPuzzle][SizeOfPuzzle]){
    int i;
    srand(time(NULL));  /** Random seed by clock. */
    for (i = 0; i < SizeOfPuzzle*2; i++) {
        int row = rand() % SizeOfPuzzle + 1;   /** Generate random numbers on rows ! */
        int col = rand() % SizeOfPuzzle + 1;   /** Generate random numbers on columns ! */
        int val = rand() % SizeOfPuzzle + 1;   /** Generate a value which will fill matrix ! */

        if (legalAssign(puzzle, row, col, val)) /** Get rights to assign value */
            puzzle[row][col] = val; /** Assign the value */
    }

    int x = counter(puzzle);     /** Declare a variable which will store how much numbers are avaiable on matrix. */
}
