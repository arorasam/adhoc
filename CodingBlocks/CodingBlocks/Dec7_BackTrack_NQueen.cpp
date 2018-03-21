#include "stdafx.h"
#define MAX_BOARD_SIZE 20
// TODO:  How to pass a 2D array, how to specify 2D array
//bool ValidatePlacement(int** arr, int i, int j)

// Complexity is O(n^n) - upto n=10 in < 1sec
// Can be optimized by keeping state for each column and diagonals
// TODO: Right diagonal dl[difference  of row and col is same for all elements on the diagonal -- may need to shift to overcome negative difference : r -c + n - 1]
// TODO: Left diagonal dr[ sum of row and col is same for all elements on the diagonal]. With this the complexity would be O(n^(n-1)) upto n=14 in < 1sec 
// TODO: use bitmask -- what's bitset<n>
// TODO: Generate all configurations
// TODO: Display all configurations
// TODO: Bitmask upto n=15,16 in < 1sec
// TODO: What's fenwick tree

bool IsSafePlacement(int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int boardSize, int row, int col)
{
	// Check for columns in this row
	for (int i = 0; i < row; i++)
	{
		if (board[i][col] == 1)
			return false;
	}
	int x = row;
	int y = col;


	// check for left diagonal

	// chekc right diag

	return true;
}

bool SolveNQueen(int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int boardSize, int currRow)
{
	if (currRow == boardSize)
	{
		return true;
	}

	for (int col = 0; col < boardSize; col++)
	{
		if (IsSafePlacement(board, 20, currRow, col))
		{
			board[currRow][col] = 1;

			if (!SolveNQueen(board, boardSize, currRow + 1))
			{
				// did not solve, reset and try again
				board[currRow][col] = 0;
			}

		}
	}
	return false;
}

