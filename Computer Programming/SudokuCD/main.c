#include "sudoku.h"

bool GameOver;
bool Start;
int choice;

int main(){

    while(!Start){
        GameOver = false;
        system("CLS");
        printf("\t\t--------------------------------------\n");
        printf("\t\t           Sudoku Project \n");
        printf("\t\t--------------------------------------\n");

        Ask();

        int puzzle[sz][sz];
        int copy[sz][sz];
        int cnt = 0;

        int i, j;

        for(i = 0; i < sz; i++){
            for(j = 0; j < sz; j++){
                puzzle[i][j] = 0;
            }
        }
        while(!GameOver){
            system("CLS");

            printf("\t\t--------------------------------------\n");
            printf("\t\t           Sudoku Project \n");
            printf("\t\t--------------------------------------\n");

            printf("\t\t Size of puzzle is %d \n",sz);
            printf("\t\t Your actual sudoku puzzle is: \n\n");
            printPuzzle(puzzle, sz);
            printf("\n");
            printf("\t\t 1 -> Change sudoku size \n");
            printf("\t\t 2 -> Inser number in position \n");
            printf("\t\t 3 -> Generate Random Puzzle \n");
            printf("\t\t 4 -> Solve puzzle \n");
            printf("\t\t 5 -> Back \n");
            printf("\t\t 6 -> Exit program ! \n\n");
            printf("\t\t Insert your choice : ");
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    main();
                    break;
                case 2:
                    copyPuzzle(puzzle, copy);
                    insertNumberInPozition(puzzle, sz);
                    break;
                case 3:
                    copyPuzzle(puzzle, copy);
                   // for(i = 1; i < boxLength(sz)+10; i++){
                        randomGeneration(puzzle);
                 //   }
                    break;
                case 4:
                    if(SolveSudoku(puzzle) == 1){
                        printPuzzle(puzzle, sz);
                    }
                    else{
                        printf("\t\t No more solutions ! !\n");
                        printf("\t\tRestart in %d seconds !\n", 10);
                        Sleep(10000);

                    }
                case 5:
                    pastePuzzle(puzzle, copy);
                    printPuzzle(puzzle, sz);
                    break;
                case 6:
                    GameOver = true;
                    break;
                default:
                    printf("Wrong choice try again :");
                    scanf("%d",&choice);
                    break;
            }
        }
    }

	return 0;
}
