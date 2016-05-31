#include "sudoku.h"


///\brief Generate intro interface.
void Intro(){
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t              Sudoku Project Developed \n");
    printf("\t\t            by Vasile Sebastian Costinel\n\n");
    printf("\t\t\t This program can automatically generate  \n");
    printf("\t\t sudoku puzzles and then solve them at your choice. \n\n");
    printf("\t\t Solutions solved : %d\n", solution);
    printf("\t\t----------------------------------------------------\n");
}

///\brief Generate chose options interface for switch .
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
///\brief Call back-up of last puzzle.
void Back(int puzzle, int copy, int SizeOfPuzzle){
    pastePuzzle(puzzle, copy);
    printPuzzle(puzzle, SizeOfPuzzle);
}

///\brief Insert number in pozition at your choice !
void InsertNumberInPozitionChoice(int puzzle, int copy, int SizeOfPuzzle){
    copyPuzzle(puzzle, copy);
    insertNumberInPozition(puzzle, SizeOfPuzzle);
}

///\brief Generate puzzle
void GenerateRandomPuzzle(int puzzle, int copy, FILE *nameOfFile, int SizeOfPuzzle){
    copyPuzzle(puzzle, copy);
    randomGeneration(puzzle);
    fprintf(nameOfFile,"\tGenerated puzzle is : \n");
    printPuzzleInFile(nameOfFile,puzzle,SizeOfPuzzle, " \n");
}

///\brief A function which will call solving parts to solve the puzzle !
void SolvePuzzle(int puzzle, FILE *fileToPrint, int SizeOfPuzzle){
    if(SolveSudoku(puzzle,fileToPrint) == 1){
        /** The solution is printed on console display. /** Generate print interface. */
        ///\ printPuzzle(puzzle, SizeOfPuzzle);

        ///\ The solution is printed on Solutions file !
        printPuzzleInFile(fileToPrint, puzzle, SizeOfPuzzle);
        fclose(fileToPrint);
        Sleep(2000);
    }
    else{
        //fprintf(fileToPrint, " There are %d solutions ", counter);
        fclose(fileToPrint);
        printf("\t\t No solutions for this puzzle ! ! !\n");
        Sleep(2000);
    }
}

///\brief Ask for size of puzzle .
///\param puzzle The respective puzzle
///\param SizeOfPuzzle Puzzle size.
void AskSize(int SizeOfPuzzle,int puzzle){
    printf("\t\t Size of puzzle is %d \n\n",SizeOfPuzzle);
    printf("\t\t Your actual sudoku puzzle is: \n\n");
    printPuzzle(puzzle, SizeOfPuzzle);
}

