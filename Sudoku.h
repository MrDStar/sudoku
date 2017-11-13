class Sudoku {
	private:
		int puzzle[9][9];
		Sudoku* next;
	public:
		Sudoku(int [9][9]);
		bool isSolved();
		void printSudoku();
		int firstFree();
};
