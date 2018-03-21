#include "stdafx.h"
#include "limits.h"

using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


int func(int floor, int plates)
{
	if (floor == 1 || floor == 0 || plates == 1)
		return floor;

	int ans = INT_MAX;
	for (int i = 1; i <= floor; i++)
	{
		// nahi toota
		int a = func(floor - i, plates);

		// toota
		int b = func(i - 1, plates - 1);
		ans = min(ans, max(a, b));
	}
	return ans;
}
int MinTrialsToDeterminePlateBreakageHeight(
	int** arr,
	int plates,
	int floors)
{

	// When there is only 1 floor, we need 1 trial. 
	// For no floors, we need 0 trials.
	for (int p = 1; p < plates; p++)
	{
		arr[p][0] = 0;
		arr[p][1] = 1;
	}

	// When there is only 1 remaining plate, we need as many trials as the number of floors
	for (int f = 1; f < floors; f++)
	{
		arr[1][f] = f;
	}

	int min = INT_MAX, result;
	for (int p = 2; p <= plates; p++)
	{
		for (int f = 2; f <= floors; f++)
		{
			arr[p][f] = INT_MAX;
			// for p plates, attempt from 1st floor upto 'f'th floor and memorize
			// min trials for p-plates and 1-f floors to be reused. 
			for (int fp = 1; fp <= f; fp++)
			{
				result = 1 + MAX(arr[p - 1][fp - 1], arr[p][f - fp]);
				if (result < arr[p][f])
					arr[p][f] = result;

			}
		}
	}
	return arr[plates][floors];
	
}


void
Exec_MinTrialsToDeterminePlateBreakageHeight()
{
	int plates, floors;
	int testCases;

	cin >> testCases;

	while (testCases--)
	{
		cin.ignore();
		cin >> plates >> floors;
		int** arr = new int*[plates + 1];
		for (int i = 0; i <= plates; i++)
		{
			arr[i] = new int[floors + 1];
		}

		// int minTrial = MinTrialsToDeterminePlateBreakageHeight(arr, plates, floors);
		int minTrial = func(floors, plates);

		cout << minTrial << endl;
		for (int i = 0; i < plates; i++)
		{
			delete arr[i];
		}
		delete arr;
	}
}