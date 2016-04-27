#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>
#define UNASSIGNED 0

int sz;

void drawPuzzle(int puzzle[sz][sz], int sz);
int Ask();
int SolveSudoku(int puzzle[sz][sz]);

#endif
