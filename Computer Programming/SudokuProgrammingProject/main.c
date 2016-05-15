#include "sudoku.h"

int main(){
FILE *fileToPrint;
fileToPrint = fopen("Solutions.out","w");
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

            printf("\t\t Size of puzzle is %d \n\n",SizeOfPuzzle);
            printf("\t\t Your actual sudoku puzzle is: \n\n");
            printPuzzle(puzzle, SizeOfPuzzle);

            ChoseOptions();
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    main();
                    break;
                case 2:
                    copyPuzzle(puzzle, copy);
                    insertNumberInPozition(puzzle, SizeOfPuzzle);
                    break;
                case 3:
                    copyPuzzle(puzzle, copy);
                    randomGeneration(puzzle);
                    fprintf(fileToPrint,"\tGenerated puzzle is : \n");
                    printPuzzleInFile(fileToPrint,puzzle,SizeOfPuzzle, " \n");
                    break;
                case 4:
                    if(SolveSudoku(puzzle,fileToPrint) == 1){
                        ///\ The solution is printed on console display
                        ///\ printPuzzle(puzzle, SizeOfPuzzle);

                        ///\ The solution is printed on Solutions file !
                        printPuzzleInFile(fileToPrint, puzzle, SizeOfPuzzle);
                        fclose(fileToPrint);
                        printf("\t\t The file was printed check it out !\n");
                        Sleep(2500);
                    }
                    else{
                        printf("\t\t No solutions ! !\n");
                        Sleep(3000);
                    }
                case 5:
                    pastePuzzle(puzzle, copy);
                    printPuzzle(puzzle, SizeOfPuzzle);
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
