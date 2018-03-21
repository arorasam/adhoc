#include "stdafx.h"
#include "cmath"
void MinimizeTowerHeightDifference(int* arr, int n, int k, int testCaseNumber)
{
	int l = 0;
	int r = n;
	int min = arr[l], max = arr[r-1];
	int minIdx = 0, maxIdx = 0;
	int sum = 0, avg = 0;
	for (int i = l; i < r; i++)
	{
		if (min > arr[i]) {
			min = arr[i];  minIdx = i;
		}
		if (max < arr[i]) {
			max = arr[i]; maxIdx = i;
		}
		sum += arr[i];
	}


	bool bringCloser = (max - min) > 2 * k;
	if (bringCloser)
	{

		// Bring all closer to the average, then diff between new min, max
		avg = ceil(sum / (r - l));
		for (int i = l; i < r; i++)
		{
			arr[i] += (arr[i] <= avg) ? k : -1 * k;
			if (i == l)
			{
				min = max = arr[i];
			}

			if (min > arr[i]) {
				min = arr[i];  minIdx = i;
			}
			if (max < arr[i]) {
				max = arr[i]; maxIdx = i;
			}
		}
	}
	cout << "# " << testCaseNumber << " : " << (max - min) << endl;
}

void Exec_MinimizeTowerHeightDifference()
{
	int testCases; 
	cin >> testCases;
	cin.ignore();

	for (int j = 1; j <= testCases; j++)
	{
		int n, k;
		cin >> k;
		cin.ignore();
		cin >> n;
		cin.ignore();
		
		int *brr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> brr[i];
		cin.ignore();
		MinimizeTowerHeightDifference(brr, n, k, j);
		delete brr;
	}
}


//int arr[] = { 1, 15, 10 };
//MinimizeTowerHeightDifference(arr, 3, 6);
//int arr[] = { 1, 15, 10, 5 };
//MinimizeTowerHeightDifference(arr, 4, 4);
