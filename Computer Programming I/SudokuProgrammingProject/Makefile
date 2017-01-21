CC=gcc
CFLAGS=-I.
DEPS = sudoku.h
OBJ = main.o Display.o essentialFunctions.o GenerateSudokuPuzzle.o SudokuSolver.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SudokuProject: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)