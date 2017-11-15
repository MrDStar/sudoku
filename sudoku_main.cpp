#include <iostream>
#include <list>
#include <string>
#include "Sudoku.h"

void readSudoku(int A[9][9]) {
  std::cout << "Please enter your 9x9 Sudoku by entering its numbers separated by spaces, use 0 for blank fields:\n";
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			std::cin >> A[i][j];
		}
	}
}

int main() {

	int A[9][9];
	std::list<Sudoku> L = {};
	std::list<Sudoku> Solutions = {};
	while(L.empty()) {
		readSudoku(A);
		Sudoku init(A);
		std::cout << "\nYou have entered:\n";
		init.printSudoku();
		std::cout << "Is this correct (y/n)? ";
		char answer;
		std::cin >> answer;
		if(answer == 'y') {
			L.push_front(init);
		}
	}

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
			Solutions.push_back(t);
		}
	}

	int solutionsCount = Solutions.size();
	std::string output;
	switch(solutionsCount) {
		case 0:
			output = "No solutions found \n";
			break;
		case 1:
			output = "1 solution found:\n\n";
			break;
		default:
			output = std::to_string(solutionsCount) + " solutions found: \n\n";
	}
	std::cout << output;
	while(!Solutions.empty()) {
		Solutions.front().printSudoku();
		Solutions.pop_front();
	}
}
