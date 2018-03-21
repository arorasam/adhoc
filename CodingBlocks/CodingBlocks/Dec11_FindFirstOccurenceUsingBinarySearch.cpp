#include "stdafx.h"

#if 0
int arr[] = { 1, 2, 2, 2, 2, 5, 6, 7, 7 };


void FindFirstOccurrenceInSortedArray(int arr[], int len, int x)
{
	int start = 0;
	int end = len;
	int mid = 0;
	int ans = 0;

	while (start <= end) // continue while even single element remains in the left sub array.
	{
		int mid = (start + end) / 2;
		if (arr[mid] == x)
		{
			ans = mid;
			end = mid - 1; 
		}
		else if (arr[mid] > x)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
}









void FindFirstOccurrenceInSortedArrat(int x, int r,int l) {
	
	// Base case
	if (l == r)
		cout << "Found first occurence of " << x << " at " << r << endl;
	else if (l > r)
		return -1; 

	int mid = (r + l) / 2;
	if (arr[mid] == x)
	{
		// check if this is the first occurrence
		FindFirstOccurrenceInSortedArrat(x, l, mid - 1);

	}
	else if (arr[mid] > x)
	{
		FindFirstOccurrenceInSortedArrat(x, l, mid - 1);
	}
	else if (arr[mid] < x)
	{
		FindFirstOccurrenceInSortedArrat(x, mid + 1, r);
	}
}

#endif
