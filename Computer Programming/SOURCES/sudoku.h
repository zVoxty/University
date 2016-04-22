#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
int SIZE; // Declare size of puzzle
int i, j; // Declare iterators

void pre_main();
bool legalAssign(int grid[SIZE][SIZE], int row, int col, int value);
void drawPuzzle(int grid[SIZE][SIZE]);
int isAvailable(int puzzle[][SIZE], int row, int col, int num);
int fillSudoku(int puzzle[][SIZE], int row, int col);
void SHOW();
int Ask();
int counter(int puzzle[SIZE][SIZE]);

#endif
