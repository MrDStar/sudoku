#include <iostream>
#include "Sudoku.h"
using namespace std;


Sudoku::Sudoku(int A[9][9]) {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) puzzle[i][j] = A[i][j];
}

void Sudoku::printSudoku() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(puzzle[i][j]) {
				cout << puzzle[i][j] << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int Sudoku::firstFree() {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
		if(!puzzle[i][j]) return 10*i+j;
	}
}

bool Sudoku::isSolved() {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
		if(!puzzle[i][j]) return false;
	}
	return true;
}
