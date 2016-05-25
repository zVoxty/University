#include "sudoku.h"
/** A function which to determine box size. */
int boxLength(int SizeOfPuzzle){
    int j;
    for(j = SizeOfPuzzle / 2 ; j >= 1; j--){
        if(j*j == SizeOfPuzzle){
            return j;
        }
    }
}

/** A function to BackUp the puzzle. */
void copyPuzzle(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int copy[SizeOfPuzzle][SizeOfPuzzle]){
    int i, j;
    for(i = 0; i < SizeOfPuzzle; i++){
        for(j = 0; j < SizeOfPuzzle; j++){
            copy[i][j] = puzzle[i][j]; /** Store the matrix into other matrix. */
        }
    }
    printf("\t\t Succesfull Backup !\n");
    Sleep(600);
}

/** An another function to BackUp the puzzle. */
void pastePuzzle(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int copy[SizeOfPuzzle][SizeOfPuzzle]){
    int i, j;
    for(i = 0; i < SizeOfPuzzle; i++){
        for(j = 0; j < SizeOfPuzzle; j++){
            puzzle[i][j] = copy[i][j]; /** Assign the backup values to puzzle. */
        }
    }
}

/** Function which will print puzzle. */
void printPuzzle(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int SizeOfPuzzle){
    int i,j;

    /** Get length of box. */
    int x = boxLength(SizeOfPuzzle);

    if(SizeOfPuzzle == 0 || x*x != SizeOfPuzzle){
            printf("\t\t         Nothing to draw ! \n");
            Sleep(500);
    }

    /** Generate print interface. */
    else{
        for(i = 0; i < SizeOfPuzzle; i++){
            printf("\t\t");
            for(j = 0; j < SizeOfPuzzle;j++){
                if(j==0)
                    printf("| ");
                if(puzzle[i][j]==0)
                    printf(". ");
                else
                    printf("%d ",puzzle[i][j]);
                if((j+1)%x==0 )
                    printf("| ");
            }
            if((i+1)%x==0 ){
                printf("\n");
            }

            printf("\n");
        }
    }
}

/** Function which will print puzzle in a file. */
void printPuzzleInFile(FILE *filename, int puzzle[SizeOfPuzzle][SizeOfPuzzle], int SizeOfPuzzle){
    int i,j;

    /** Get length of box. */
    int x = boxLength(SizeOfPuzzle);


    if(SizeOfPuzzle == 0 || x*x != SizeOfPuzzle){
            fprintf(filename,"Nothing to draw ! \n");
    }
    /** Generate print interface. */
    else{
        for(i = 0; i < SizeOfPuzzle; i++){
            for(j = 0; j < SizeOfPuzzle;j++){
                if(j==0)
                    fprintf(filename,"| ");
                if(puzzle[i][j]==0)
                    fprintf(filename,". ");
                else
                    fprintf(filename,"%d ",puzzle[i][j]);
                if((j+1)%x==0 )
                    fprintf(filename,"| ");
            }
            if((i+1)%x==0 ){
                fprintf(filename,"\n");
            }
            fprintf(filename,"\n");
        }
        if(SizeOfPuzzle == 4){
            fprintf(filename,"------------\n\n");
        }
        if(SizeOfPuzzle == 9){
            fprintf(filename,"------------------------\n\n");
        }
        if(SizeOfPuzzle == 16){
            fprintf(filename,"-----------------------------------------------\n\n");
        }
    }
}

/** Function which will insert number in specificated position. */
void insertNumberInPozition(int puzzle[SizeOfPuzzle][SizeOfPuzzle], int SizeOfPuzzle){
    int pos1, pos2, nr;
    int s = 1;

    while(s){
        system("CLS"); /** Use clear tool to delete the console */

        Intro();

        printPuzzle(puzzle,SizeOfPuzzle);
        printf("\t\t Insert (number, pos1, pos2) 0 = stop: ");
        scanf("%d%d%d", &nr, &pos1, &pos2);
        if(nr == 0){
            break;
        }

        if(nr > SizeOfPuzzle || pos1 > SizeOfPuzzle || pos2 >SizeOfPuzzle){
            printf("\t\t Numbers is too large !\n");
            Sleep(2000);
        }

        else{
            puzzle[pos1-1][pos2-1] = nr;
        }
    }
}

/** Ask function as well as it's called just ask user which will be the size of puzzle. */
int Ask(){
	printf("\t\t Insert size of puzzle : ");
	scanf("%d",&SizeOfPuzzle);

	return SizeOfPuzzle;
}

/** Counter function will return how many numbers shoud be finded in our sudoku puzzle. */
int counter(int puzzle[SizeOfPuzzle][SizeOfPuzzle]){
    int i,j;
	int count = 0;  /** Declare a counter. */
	for(i = 0; i < SizeOfPuzzle; i++){
		for(j = 0; j < SizeOfPuzzle; j++){
			if(puzzle[i][j]!=0){
				count++;  /** Increase counter when pozition is not equal to 0. */
			}
		}
	}
	return count; /** Return counter value. */
}

/** A function which will check if file is open */
bool OpenFiles(FILE *file){
    if(file == NULL){
        return false;
        exit(1);
    }
    else{
        return true;
    }
}
