#include "stdafx.h"


void FindSqureRootUsingBinarySearch(int x, int Precision)
{
	int end = x;
	int start = 0;
	int mid = x / 2;
	while (start < end)
	{

		if (mid * mid == x)
			cout << "Sqrt : " << mid << endl;
	}


}