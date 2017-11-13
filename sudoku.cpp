#include <iostream>
using namespace std;

class Sudoku {
	private:
		int puzzle[9][9];
		bool solved;
	public:
		Sudoku(int [9][9]);
		bool isSolved();
		void printSudoku();
};

Sudoku::Sudoku(int A[9][9]) {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) puzzle[i][j] = A[i][j];
}

bool Sudoku::isSolved() {
	return solved;
}

void Sudoku::printSudoku() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << " ";
			if(puzzle[i][j]) {
				cout << puzzle[i][j];
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	int A[9][9] = {{7,0,0,0,4,0,0,0,9},
	               {0,3,1,5,0,0,0,0,4},
								 {0,6,4,0,8,9,0,0,0},
								 {0,2,0,0,0,0,4,0,0},
								 {8,0,0,0,3,0,0,0,1},
								 {0,0,5,0,0,0,0,3,0},
								 {0,0,0,4,7,0,1,2,0},
								 {1,0,0,0,0,2,6,8,0},
								 {2,0,0,0,1,0,0,0,5}};
	Sudoku S(A);
	S.printSudoku();
}
