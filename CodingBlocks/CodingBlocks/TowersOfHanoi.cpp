#include "stdafx.h"

void ExecTowerOfHanoi()
{
	cout << "TowersOfHanoi: Enter # of disks to move" << endl;
	int n = 0;
	cin >> n;
	int result = TowersOfHanoi(n, 'A', 'B', 'C');
	cout << result;

}

int
TowersOfHanoi(int n, char src, char tgt, char helper)
{
	// Base Case
	int result = 0;
	if (n == 0)
		return 0;

	// Recursive Case: move n-1 disk from source to helper
	result += TowersOfHanoi(n - 1, src, helper, tgt);

	// Move nth disk from helper --> tgt;
	cout << "Move " << n << "th disk from " << src << " to " << tgt << endl;
	result++;

	// Move the n-1 disk from helper onto the target using the source tower
	result += TowersOfHanoi(n - 1, helper, tgt, src);

	return result;
}