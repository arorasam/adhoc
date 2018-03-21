#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

// TODO: Replace in-built with Merge Sort
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}


void ReadInput()
{
	vector<pair<int, int>> inputTimes;
	int tests;
	cin >> tests;
	int n;

	while (tests--)
	{
		cin >> n;
		//for(int i = 0)

	}


}


int BuildSchedule(vector<pair<int, int>> inputs, int n)
{
	sort(inputs.begin(), inputs.end(), compare);

	// complete the first activity
	int fin = inputs[0].second;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (inputs[i].first >= fin)
		{
			ans++;
			fin = inputs[i].second;
		}

	}

	return ans;
}