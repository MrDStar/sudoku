sudoku : sudoku_main.o Sudoku.o
	c++ -o sudoku sudoku_main.o Sudoku.o

sudoku_main.o : sudoku_main.cpp Sudoku.h
	c++ -c sudoku_main.cpp

Sudoku.o : Sudoku.cpp Sudoku.h
	c++ -c Sudoku.cpp
