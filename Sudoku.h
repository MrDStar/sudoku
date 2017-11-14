class Sudoku {
	private:
		int puzzle[9][9];
		Sudoku* next;
	public:
		Sudoku(int [9][9]);
		bool isSolved();
		bool isValid();
		void printSudoku();
		int firstFree();
		int countNonzero();
		void setValue(int,int);
};

class SudokuStack {
	public:
		Sudoku* first;
}
