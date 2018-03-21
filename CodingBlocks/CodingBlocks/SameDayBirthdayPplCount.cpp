
#include "stdafx.h"
using namespace std;

int MinPeopleSamedayBirthday() {

	float prob, currentProb;
	cin >> prob;

	int n = 0;
	currentProb = 1.0;

	if (prob == 1.0)
	{
		cout << 366 << endl;
	}
	else
	{
		do
		{
			currentProb *= (365.0 - (n++)) / 365.0;
		} while ((1 - currentProb) <= prob);

		cout << n << endl;
	}

	return 0;
}