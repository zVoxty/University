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
