#include <iostream>
#include <list>
#include "Sudoku.h"

int main() {
	int A[9][9] = {{0,4,9, 0,0,8, 0,0,0},
	               {0,0,0, 0,2,0, 0,0,7},
		       {0,3,0, 0,0,0, 0,8,0},

		       {0,0,0, 3,0,9, 0,6,8},
		       {0,0,0, 0,8,0, 9,0,4},
		       {0,5,0, 0,0,6, 0,0,0},
		       
		       {0,6,0, 0,0,3, 0,2,0},
		       {5,0,0, 0,0,0, 7,9,6},
		       {4,0,0, 0,0,5, 0,0,0}};

  Sudoku initial(A);
	std::list<Sudoku> L = {};
	L.push_front(initial);
	while(!L.empty()) {
		Sudoku t = L.front();
		L.pop_front();
		int firstFree = t.firstFree();
		if (firstFree != -1){
			for(int i=1; i<=9; i++) {
				if(t.setValue(firstFree,i)) {
					L.push_front(t);
				}
			}
		}
		else {
			t.printSudoku();
		}
	}
}
