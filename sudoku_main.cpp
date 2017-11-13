#include <iostream>
#include "Sudoku.h"
using namespace std;

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
	cout << S.firstFree()<<endl;
}
