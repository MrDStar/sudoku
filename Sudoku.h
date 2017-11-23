class Sudoku {
	private:
		int puzzle[9][9];
	public:
		Sudoku(int [9][9]);
		bool isSolved();
		bool isValid();
		void printSudoku();
		void printSudokuFile();
		int firstFree();
		int countNonzero();
		bool setValue(int,int);
};
