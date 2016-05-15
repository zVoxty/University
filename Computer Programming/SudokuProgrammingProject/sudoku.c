#include "sudoku.h"

///\ Searches the puzzle to find an entry that is still unassigned. If
///\   found, the reference parameters row, col will be set the location
///\   that is unassigned, and true is returned. If no unassigned entries
///\   remain, false is returned.
int FindUnassigned(int puzzle[sz][sz],int *row,int *col){
    for(*row = 0;*row < sz;(*row)++){
        for(*col = 0;*col < sz;(*col)++){
            if(puzzle[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

///\ Returns a boolean which indicates whether it will be legal to assign
///\   num to the given row,col location.
int isSafe(int puzzle[sz][sz],int row,int col,int num){
    int x = boxLength(sz);

    ///\ Check if 'num' is not already placed in current row,
    ///\   current column and current box
    if(UsedInRow(puzzle,row,num) == 0 && UsedInCol(puzzle,col,num) == 0 &&
       UsedInBox(puzzle,(row - row%x),(col - col%x),num) == 0) return 1;
    return 0;
}

///\ Returns a boolean which indicates whether any assigned entry
///\ in the specified row matches the given number.
int UsedInRow(int puzzle[sz][sz],int row,int num){
    int i;
    for(i = 0;i < sz;i++){
        if(puzzle[row][i] == num) return 1;
    }
    return 0;
}

///\ Returns a boolean which indicates whether any assigned entry
///\   in the specified column matches the given number. */
int UsedInCol(int puzzle[sz][sz],int col,int num){
    int i;
    for(i = 0;i < sz;i++){
        if(puzzle[i][col] == num) return 1;
    }
    return 0;
}

///\  Returns a boolean which indicates whether any assigned entry
///\    within the specified box matches the given number. */
int UsedInBox(int puzzle[sz][sz],int BoxStartRow,int BoxStartCol,int num){
    int i,j;
    int x = boxLength(sz);
    for(i = 0;i<x;i++){
        for(j = 0;j<x;j++){
            if(puzzle[i+BoxStartRow][j+BoxStartCol] == num) return 1;
        }
    }
    return 0;
}

///\  Takes a partially filled-in grid and attempts to assign values to
///\   all unassigned locations in such a way to meet the requirements
///\   for Sudoku solution (non-duplication across rows, columns, and boxes) */
int SolveSudoku(int puzzle[sz][sz]){
    int row,col;
    int num;

    ///\  If there is no unassigned location, we are done
    if(FindUnassigned(puzzle,&row,&col) == 0){
        return 1;
    }

    ///\  consider digits 1 to SZ
    for(num = 1;num <= sz;num++){

        ///\  if looks promising
        if(isSafe(puzzle,row,col,num) == 1){

            ///\  make tentative assignment
            puzzle[row][col] =  num;

            ///\  return, if success, yay!
            if(SolveSudoku(puzzle) == 1){
                printPuzzle(puzzle, sz);
                printf("\n");
            }

            ///\  failure, unmake & try again (BACKTRACK)
            puzzle[row][col] = UNASSIGNED;
        }
    }

    return 0; ///\  this triggers backtracking
}



















