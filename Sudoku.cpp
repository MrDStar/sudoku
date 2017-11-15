#include <iostream>
#include "Sudoku.h"


Sudoku::Sudoku(int A[9][9]) {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) puzzle[i][j] = A[i][j];
}

void Sudoku::printSudoku() {
	std::cout << "╔═══════╤═══════╤═══════╗" << std::endl;
	for(int i=0; i<9; i++) {
		std::cout << "║ ";
		for(int j=0; j<9; j++) {
			if(puzzle[i][j]) {
				std::cout << puzzle[i][j];
			}
			else {
				std::cout << " ";
			}
			if(j == 2 || j == 5) {
				std::cout << " │ ";
			}
			else if(j == 8) {
				std::cout << " ║";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		if(i == 2 || i == 5) {
			std::cout << "╟───────┼───────┼───────╢" << std::endl;
		}
	}
	std::cout << "╚═══════╧═══════╧═══════╝" << std::endl;

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
	// Set value
	puzzle[x][y] = value;
	// Determine boundaries of sub block
	int subMinX,subMaxX,subMinY,subMaxY;
	switch(x%3) {
		case 0 :
			subMinX = x;
			subMaxX = x+2;
			break;
		case 1 :
			subMinX = x-1;
			subMaxX = x+1;
			break;
		case 2:
			subMinX = x-2;
			subMaxX = x;
			break;
	}
	switch(y%3) {
		case 0:
			subMinY = y;
			subMaxY = y+2;
			break;
		case 1:
			subMinY = y-1;
			subMaxY = y+1;
			break;
		case 2:
		subMinY = y-2;
		subMaxY = y;
		break;
	}
	// Check sub block
	for(int i=subMinX; i<=subMaxX; i++) {
		for(int j=subMinY; j<=subMaxY; j++) {
			if( (i!=x || j != y) && puzzle[i][j] == puzzle[x][y] ) {
				return false;
			}
		}
	}
	// Check column
	for(int i=0; i<9; i++) {
		if(y != i && puzzle[x][i] == puzzle[x][y] ) {
		  return false;
		}
	}
	// Check row
	for(int i=0; i<9; i++) {
		if(x != i && puzzle[i][y] == puzzle[x][y] ) {
		  return false;
		}
	}
	return true;
}
