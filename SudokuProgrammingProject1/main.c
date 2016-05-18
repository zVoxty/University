#include "sudoku.h"

int main(){
    FILE *fileToPrint;
    fileToPrint = fopen("Solutions.out","w");
    int IteratiiSolve = 1000;

    ///\ Create Interface of Program
    while(!Start){
        GameOver = false;
        system("CLS");
        Intro();

        Ask();

        int puzzle[SizeOfPuzzle][SizeOfPuzzle];
        int copy[SizeOfPuzzle][SizeOfPuzzle];
        int i, j;
        ///\ Here is generated the puzzle full with 0
        for(i = 0; i < SizeOfPuzzle; i++){
            for(j = 0; j < SizeOfPuzzle; j++){
                puzzle[i][j] = 0;
            }
        }
        while(!GameOver){
            system("CLS");

            Intro();
            AskSize(SizeOfPuzzle, puzzle);
            ChoseOptions();

            scanf("%d",&choice);

            switch(choice){
                case 1:
                    main();
                    break;
                case 2:
                    InsertNumberInPozitionChoice(puzzle, copy, SizeOfPuzzle);
                    break;
                case 3:
                    GenerateRandomPuzzle(puzzle, copy, fileToPrint, SizeOfPuzzle);
                    break;
                case 4:
                    SolvePuzzle(puzzle, fileToPrint, SizeOfPuzzle, IteratiiSolve);
                    break;
                case 5:
                    Back(puzzle, copy, SizeOfPuzzle);
                    break;
                case 6:
                    GameOver = true;
                    Start = true;
                    break;
                default:
                    printf("\t\t Wrong choice try again :");
                    scanf("%d",&choice);
                    break;
            }
        }
    }

	return 0;
}
