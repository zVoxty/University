#include "sudoku.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= DISPLAY =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/*
void SHOW(){
	printf("--------------------------------------------------\n");
	printf("		Sudoku Solver By Voxty\n");
	printf("--------------------------------------------------\n\n");
	printf("\t 1 -> Generate a Sudoku Puzzle  \n");
	printf("\t 2 -> Solve Generated Puzzle \n");
	printf("\t 3 -> Exit program ! \n\n");
}
*/

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= GENERATION PART =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
//\ Function which will check if the value exist on actual row .
bool existsRow(int puzzle[SIZE][SIZE], int row, int value) {
	int col;
    for (col = 0; col < SIZE; col++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

//\ Function which will check if the value exist on actual Col .
bool existsCol(int puzzle[SIZE][SIZE], int col, int value) {
	int row;
    for (row = 0; row < SIZE; row++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

//\ Function which will check if the value exist on actual box .
bool existsBox(int puzzle[SIZE][SIZE], int boxRow, int boxCol, int value) {
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

//\ Give permission to insert value in primary matrix !
bool legalAssign(int puzzle[SIZE][SIZE], int row, int col, int value) {
    return !existsRow(puzzle, row, value) && !existsCol(puzzle, col, value) && !existsBox(puzzle, row-row%3, col-col%3, value);
}

//\ A functions which will print matrix with little design !
void drawPuzzle(int puzzle[SIZE][SIZE]) {
	int row,col;
	int j,x;
	for(j = SIZE / 2; j >= 2; j--){
		if(pow(j,2) == SIZE){
		    printf("\n\n");
		    for (row = 0; row < SIZE; row++) {
		        printf("|");
		        for (col = 0; col < SIZE; col++) {
		            printf("%2d",puzzle[row][col]);
		            if ((col+1) % j == 0) printf("|");
		        }
		        printf("\n");
		        if ((row+1) % j == 0) {
		                printf("\n");
		        }
		    }
		}
	}

}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= SOLVE PART =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
//\ Functions which will return how much numbers are avaiable on puzzle .
int counter(int puzzle[SIZE][SIZE]){
	int count = 0;  //\ Declare a counter
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			if(puzzle[i][j]!=0){
				count++;  //\ Increase counter when pozition is not equal to 0.
			}
		}
	}
	return count; //\ Return counter value
}


int fillSudoku(int puzzle[][SIZE], int row, int col)
{
    int i;
    if(row<SIZE && col<SIZE)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<SIZE) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<SIZE) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i = 0; i < SIZE; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<SIZE)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<SIZE)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int isAvailable(int puzzle[][SIZE], int row, int col, int num)
{
	int i, j;
	for(j = SIZE / 2; j >= 2; j--){
		if(pow(j,2) == SIZE){
		    int rowStart = (row/j) * j;
		    int colStart = (col/j) * j;

		    for(i=0; i<SIZE; ++i)
		    {
		        if (puzzle[row][i] == num) return 0;
		        if (puzzle[i][col] == num) return 0;
		        if (puzzle[rowStart + (i%j)][colStart + (i/j)] == num) return 0;
		    }
		    return 1;
		}
	}
}

int Ask(){
	printf("Insert Size of Puzzle : ");
		scanf("%d",&SIZE);
		
	return SIZE;
}

void pre_main(){
	
	Ask();   //\ Call Ask function to determine the size of puzzle !
	int puzzle[SIZE][SIZE];
	//\ Fill all positions with number 0 .
    for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			puzzle[i][j] = 0;
		}
	}

	srand(time(NULL));  //\ Random seed by clock.
    for (i = 0; i < SIZE*2; i++) {
        int row = rand() % SIZE + 1;   //\ Generate random numbers on rows !
        int col = rand() % SIZE + 1;   //\ Generate random numbers on columns !
        int val = rand() % SIZE + 1;   //\ Generate a value which will fill matrix !
        if (legalAssign(puzzle, row, col, val))
            puzzle[row][col] = val;
    }

    printf("Initial puzzle:\n");
    int x = counter(puzzle);     //\ Declare a variable which will store how much numbers are avaiable on matrix.

	printf(" There are %d numbers avaiable, program have to find %d numbers !", x, SIZE*SIZE - x);
    drawPuzzle(puzzle);


    printf("Solved puzzle :");
    if(fillSudoku(puzzle, 0, 0))   //\ If function fill Sudoku return 1 puzzle can be solved.
		drawPuzzle(puzzle);
    else printf("\n\nNO SOLUTIONS\n\n");  //\ Otherwise there are no solutions !

}
