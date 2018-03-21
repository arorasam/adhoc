#include "stdafx.h"
#include <algorithm>
#include <vector>

//A religious king wants to build the largest temple in his kingdom.
//To build the largest temple he needs to find the area of the largest suitable land.
//Given co - ordinates which denotes rivers flowing through the point horizontally as well as vertically, 
//find the largest area possible to make the grand temple

void DetermineBiggestTempleSite(vector<int> Xes, vector<int> Ys, int numOfPoints)
{
	sort(Xes.begin(), Xes.end());
	sort(Ys.begin(), Ys.end());
	int xDelta = 0, yDelta = 0; 
	vector<int>::iterator iter;
	int prevValue = 0;
	for (iter = Xes.begin(); iter != Xes.end(); iter++)
	{
		xDelta = max(xDelta, abs(*iter - prevValue));
		prevValue = *iter;

	}
	prevValue = 0;
	for (iter = Ys.begin(); iter != Ys.end(); iter++)
	{
		yDelta = max(yDelta, abs(*iter - prevValue));
		prevValue = *iter;
	}

	// Reduce each dimension by to account for boundaries.
	cout << (xDelta - 1 ) * (yDelta - 1);

}

void
Exec_DetermineBiggestTempleSite()
{
	int numOfPoints;
	cin >> numOfPoints;
	cin.ignore();
	vector<int> Xes;
	vector<int> Ys;

	for (int i = 0; i < numOfPoints; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		Xes.push_back(x);
		Ys.push_back(y);
	}

	DetermineBiggestTempleSite(Xes, Ys, numOfPoints);
}

