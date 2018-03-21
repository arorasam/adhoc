#include "stdafx.h"

#define N 9

void PrintMatrix(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void GetSubGridOrigin(int sqrtN, int *r, int *c)
{
	int row = *r;
	int col = *c;
	row = (row / sqrtN) * sqrtN;
	col = (col / sqrtN) * sqrtN;

	*r = row;
	*c = col;
}

bool IsSafePlacement(int arr[N][N], int r, int c, int x)
{
	// check presence in row and col
	for (int i = 0; i < N; i++)
		if (arr[r][i] == x || arr[i][c] == x)
			return false;

	// check presence in subgrid
	int origR = r;
	int origC = c;
	int n = sqrt(N);
	GetSubGridOrigin(n, &origR, &origC);
	for (int i = origR; i < origR + n; i++)
		for (int j = origC; j < origC + n; j++)
		{
			if (arr[i][j] == x)
				return false;
		}

	return true;
}

bool SolveSudoku(int arr[N][N], int row, int col)
{
	// Base case, when we reach N row, all columns must be filled as well.
	if (row == N)
	{
		PrintMatrix(arr);
		return true;
	}
	else if (col == N)
	{
		// Wrap over to next row
		bool colResult = SolveSudoku(arr, row + 1, 0);
		return colResult;
	}

	if (arr[row][col] != 0)
	{
		// Move to next column
		return SolveSudoku(arr, row, col + 1);
	}

	for (int x = 1; x < 10; x++)
	{
		if (IsSafePlacement(arr, row, col, x))
		{
			arr[row][col] = x;
			if (SolveSudoku(arr, row, col + 1))
			{
				return true;
			}
			else
			{
				arr[row][col] = 0;
				continue;
			}
		}
	}

	return (arr[row][col] != 0); //false;
}


//void ReadInput()
//{
//
//}
void
ExecSudoku()
{
	int arr[N][N] = {
		{ 5,3,0,0,7,0,0,0,0 },
		{ 6,0,0,1,9,5,0,0,0 },
		{ 0,9,8,0,0,0,0,6,0 },
		{ 8,0,0,0,6,0,0,0,3 },
		{ 4,0,0,8,0,3,0,0,1 },
		{ 7,0,0,0,2,0,0,0,6 },
		{ 0,6,0,0,0,0,2,8,0 },
		{ 0,0,0,4,1,9,0,0,5 },
		{ 0,0,0,0,8,0,0,7,9 }
	};

	SolveSudoku(arr, 0, 0);

}
