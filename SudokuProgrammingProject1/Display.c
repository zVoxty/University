#include "sudoku.h"

void Intro(){
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t              Sudoku Project Developed \n");
    printf("\t\t            by Vasile Sebastian Costinel\n\n");
    printf("\t\t\t This program can automatically generate  \n");
    printf("\t\t sudoku puzzles and then solve them at your choice. \n\n");
    printf("\t\t There are some tips : \n");
    printf("\t\t 1 - Solve Sudoku at a size of:\n\n");
    printf("\t\t\t - 4x4 = 100 percent chance !\n");
    printf("\t\t\t - 9x9 = 80 percent chance !\n");
    printf("\t\t\t - 16x16 = 50 percent chance !\n");
    printf("\t\t\t - 25x25 = 10 percet chance !\n");
    printf("\t\t----------------------------------------------------\n");
}

void ChoseOptions(){
    printf("\n");
    printf("\t\t 1 -> Change sudoku size \n");
    printf("\t\t 2 -> Inser number in position \n");
    printf("\t\t 3 -> Generate Random Puzzle \n");
    printf("\t\t 4 -> Solve puzzle \n");
    printf("\t\t 5 -> Back \n");
    printf("\t\t 6 -> Exit program ! \n\n");
    printf("\t\t Insert your choice : ");
}

void Back(int puzzle, int copy, int SizeOfPuzzle){
    pastePuzzle(puzzle, copy);
    printPuzzle(puzzle, SizeOfPuzzle);
}

void InsertNumberInPozitionChoice(int puzzle, int copy, int SizeOfPuzzle){
    copyPuzzle(puzzle, copy);
    insertNumberInPozition(puzzle, SizeOfPuzzle);
}

void GenerateRandomPuzzle(int puzzle, int copy, FILE *nameOfFile, int SizeOfPuzzle){
    copyPuzzle(puzzle, copy);
    randomGeneration(puzzle);
    fprintf(nameOfFile,"\tGenerated puzzle is : \n");
    printPuzzleInFile(nameOfFile,puzzle,SizeOfPuzzle, " \n");
}

void SolvePuzzle(int puzzle, FILE *fileToPrint, int SizeOfPuzzle){
    if(SolveSudoku(puzzle,fileToPrint) == 1){
        ///\ The solution is printed on console display
        ///\ printPuzzle(puzzle, SizeOfPuzzle);

        ///\ The solution is printed on Solutions file !
        printPuzzleInFile(fileToPrint, puzzle, SizeOfPuzzle);
        fclose(fileToPrint);
        printf("\t\t The file was printed check it out !\n");
        Sleep(2000);
    }
    else{
        //fprintf(fileToPrint, " There are %d solutions ", counter);
        fclose(fileToPrint);
        printf("\t\t No more solutions check your file ! !\n");
        Sleep(2000);
    }
}

void AskSize(int SizeOfPuzzle,int puzzle){
    printf("\t\t Size of puzzle is %d \n\n",SizeOfPuzzle);
    printf("\t\t Your actual sudoku puzzle is: \n\n");
    printPuzzle(puzzle, SizeOfPuzzle);
}
