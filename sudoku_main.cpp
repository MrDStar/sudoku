#include <iostream>
#include <fstream>
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
	std::ofstream outfile;
	outfile.open("sudoku.txt");
	int A[9][9];
	int solutioncount = 0;
	std::list<Sudoku> L = {};
	std::list<Sudoku> Solutions = {};
	while(L.empty()) {
		readSudoku(A);
		Sudoku init(A);
		std::cout << "\nYou have entered:\n";
		init.printSudoku();
		outfile << "Unsolved Sudoku:\n";
		outfile.close();
		init.printSudokuFile();
		L.push_front(init);
	}
	
	outfile.open("sudoku.txt", std::ios::app);
	outfile << "Solution(s):\n";
	outfile.close();
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
			t.printSudokuFile();
			if(solutioncount++ == 1000000) {
				break;
			}
		}
	}
	outfile.open("sudoku.txt", std::ios::app);
	outfile << solutioncount;
	outfile << " solutions found\n";
	outfile.close();

}
