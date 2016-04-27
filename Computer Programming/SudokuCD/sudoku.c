#include "sudoku.h"

int boxLength(int sz){
    int j;
    for(j = sz / 2 ; j >= 1; j--){
        if(j*j == sz){
            return j;
        }
    }
}

void copyPuzzle(int puzzle[sz][sz], int copy[sz][sz]){
    int i, j;
    for(i = 0; i < sz; i++){
        for(j = 0; j < sz; j++){
            copy[i][j] = puzzle[i][j];
        }
    }
    printf("\t\t Succesfull Backup !\n");
    Sleep(1000);
}

void pastePuzzle(int puzzle[sz][sz], int copy[sz][sz]){
    int i, j;
    for(i = 0; i < sz; i++){
        for(j = 0; j < sz; j++){
            puzzle[i][j] = copy[i][j];
        }
    }
}

void printPuzzle(int puzzle[sz][sz], int sz){
    int i,j;
    int x = boxLength(sz);
    if(sz == 0 || x*x != sz){
            printf("\t\t         Nothing to draw ! \n");
            Sleep(500);
    }
    else{
            for(i = 0; i < sz; i++){
                printf("\t\t");
                for(j = 0; j < sz;j++){
                   if(j==0)
                        printf("| ");
                   if(puzzle[i][j]==0)
                        printf(". ");
                   else
                        printf("%d ",puzzle[i][j]);
                   if((j+1)%x==0 )
                        printf("| ");
                }

                if((i+1)%x==0 )
                    printf("\n");

                printf("\n");
            }

    }
}

void insertNumberInPozition(int puzzle[sz][sz], int sz){
    int pos1, pos2, nr;
    int s = 1;

    while(s){
        system("CLS");

        printf("\t\t--------------------------------------\n");
        printf("\t\t           Sudoku Project \n");
        printf("\t\t--------------------------------------\n");

        printPuzzle(puzzle,sz);
        printf("\t\t Insert (number, pos1, pos2) 0 = stop: ");
        scanf("%d%d%d", &nr, &pos1, &pos2);
        if(nr == 0){
            break;
        }
        if(nr > sz || pos1 > sz || pos2 >sz){
            printf("\t\t Numbers is too large !\n");
            Sleep(2000);
        }
        else{
            puzzle[pos1-1][pos2-1] = nr;
        }
    }
}

int Ask(){
	printf("\t\t Insert size of puzzle : ");
	scanf("%d",&sz);

	return sz;
}

int counter(int puzzle[sz][sz]){
    int i,j;
	int count = 0;  //\ Declare a counter
	for(i = 0; i < sz; i++){
		for(j = 0; j < sz; j++){
			if(puzzle[i][j]!=0){
				count++;  //\ Increase counter when pozition is not equal to 0.
			}
		}
	}
	return count; //\ Return counter value
}

/* RANDOM GENERATION FUNCTIONS */
bool existsRow(int puzzle[sz][sz], int row, int value) {
	int col;
    for (col = 0; col < sz; col++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

//\ Function which will check if the value exist on actual Col .
bool existsCol(int puzzle[sz][sz], int col, int value) {
	int row;
    for (row = 0; row < sz; row++) {
        if (puzzle[row][col] == value) {
            return true;
        }
    }
    return false;
}

//\ Function which will check if the value exist on actual box .
bool existsBox(int puzzle[sz][sz], int boxRow, int boxCol, int value) {
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
bool legalAssign(int puzzle[sz][sz], int row, int col, int value) {
    int x = boxLength(sz);
    return !existsRow(puzzle, row, value) && !existsCol(puzzle, col, value) && !existsBox(puzzle, row-row%x, col-col%x, value);
}

void randomGeneration(int puzzle[sz][sz]){
    int i;
    srand(time(NULL));  //\ Random seed by clock.
    for (i = 0; i < sz*2; i++) {
        int row = rand() % sz + 1;   //\ Generate random numbers on rows !
        int col = rand() % sz + 1;   //\ Generate random numbers on columns !
        int val = rand() % sz + 1;   //\ Generate a value which will fill matrix !
        if (legalAssign(puzzle, row, col, val))
            puzzle[row][col] = val;
    }

    int x = counter(puzzle);     //\ Declare a variable which will store how much numbers are avaiable on matrix.
	//printf("\t\t Sudoku puzzle succesfull generated !!\n\t\t There are %d numbers avaiable, program have to find %d numbers ! \n", x, sz*sz - x);
	//Sleep(1000);
}

/*SOLVE PART 1*/

/* Searches the puzzle to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
//================================================================================
int FindUnassigned(int puzzle[sz][sz],int *row,int *col){
    for(*row = 0;*row < sz;(*row)++){
        for(*col = 0;*col < sz;(*col)++){
            if(puzzle[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

int UsedInRow(int puzzle[sz][sz],int row,int num){
    int i;
    for(i = 0;i < sz;i++){
        if(puzzle[row][i] == num) return 1;
    }
    return 0;
}

int UsedInCol(int puzzle[sz][sz],int col,int num){
    int i;
    for(i = 0;i < sz;i++){
        if(puzzle[i][col] == num) return 1;
    }
    return 0;
}

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

int isSafe(int puzzle[sz][sz],int row,int col,int num){
    int x = boxLength(sz);
    if(UsedInRow(puzzle,row,num) == 0 && UsedInCol(puzzle,col,num) == 0 &&
       UsedInBox(puzzle,(row - row%x),(col - col%x),num) == 0) return 1;
    return 0;
}

int SolveSudoku(int puzzle[sz][sz]){
    int row,col;

    if(FindUnassigned(puzzle,&row,&col) == 0)
        return 1;
    int num;

    for(num = 1;num <= sz;num++){
        if(isSafe(puzzle,row,col,num) == 1){
            puzzle[row][col] =  num;
            if(SolveSudoku(puzzle) == 1){

                printPuzzle(puzzle, sz);
                printf("\n");

            }

            //backtrack here
            puzzle[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

/*SOLVE PART 2*/

int fillSudoku(int puzzle[][sz], int row, int col)
{
    int i;
    if(row<sz && col<sz)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<sz)
				return fillSudoku(puzzle, row, col+1);
            else if((row+1)<sz)
				return fillSudoku(puzzle, row+1, 0);
            else
				return 1;
        }
        else
        {
            for(i = 0; i < sz; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1) < sz)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<sz)
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
    else
 		return 1;
}

int isAvailable(int puzzle[][sz], int row, int col, int num)
{
	int i, j;
	for(j = sz / 2; j >= 2; j--){
		if(pow(j,2) == sz){
		    int rowStart = (row/j) * j;
		    int colStart = (col/j) * j;

		    for(i=0; i<sz; ++i)
		    {
		        if (puzzle[row][i] == num) return 0;
		        if (puzzle[i][col] == num) return 0;
		        if (puzzle[rowStart + (i%j)][colStart + (i/j)] == num) return 0;
		    }
		    return 1;
		}
	}
}



















