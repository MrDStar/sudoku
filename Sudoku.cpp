#include <iostream>
#include "Sudoku.h"


Sudoku::Sudoku(int A[9][9]) {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) puzzle[i][j] = A[i][j];
}

void Sudoku::printSudoku() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(puzzle[i][j]) {
				std::cout << puzzle[i][j] << " ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

int Sudoku::firstFree() {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
		if(!puzzle[i][j]) return 10*i+j;
	}
	return -1;
}

bool Sudoku::isSolved() {
	return firstFree() == -1;
}

int Sudoku::countNonzero() {
	int count = 0;
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
		if(puzzle[i][j]) count++;
	}
	return count;
}

bool Sudoku::setValue(int pos, int value) { // insert new value and check validity
	int x = pos / 10;
	int y = pos % 10;
	if(!puzzle[x][y]) puzzle[x][y] = value;
	int subMinX,subMaxX,subMinY,subMaxY;

}
