#include "stdafx.h"
#define N 250
#define M 50
#define MIN 0


bool Recursive_PermuteCoinChanges(int amount, int denominations[], int denominationCount, int &waysToChange)
{
	// Base case
	if (amount < denominations[0])
	{
		//cout << "Can't change - amount smaller than smallest coin. Return to last stack " << amount << endl;
		return false;
	}

	// When amount < smallest coin, we can't produce change.
	//if (remainingAmount == 0)
	//{
	//	waysToChange++;
	//	cout << "**** found ****" << endl;
	//	return true;
	//}
	//else if (remainingAmount < 0)
	//{
	//	cout << "Can't change negative amount" << remainingAmount << endl;
	//	return false;

	//}
	//else 
	{
		// recursion
		for (int i = 0; i < denominationCount; i++)
		{
			int newRemainingAmount = amount - denominations[i];
			cout << "Amount: " << amount << "\t using coin: " << denominations[i] << "\t remains: " << newRemainingAmount << "\t waysToChange: " << waysToChange << endl;

			if (newRemainingAmount == 0)
			{
				waysToChange++;
				cout << "\t\t\t\t\t**** found with coin " << denominations[i] << endl;
				// coins being distinct, no other coin will satisfy this remaining amount.
				// so backtrack.
				return true;
			}
			else if (newRemainingAmount > 0)
			{
				bool ret = Recursive_PermuteCoinChanges(newRemainingAmount, denominations, denominationCount, waysToChange);
				if (ret)
				{
					cout << ", " << denominations[i] << endl;
				}
			}
		}
	}
	return false;
}

//Given a value N, if we want to make change for N cents, 
// and we have infinite supply of each of S = { S1, S2, .. , Sm } valued coins, 
//In how many ways can we make the change ? The order of coins doesn’t matter.
int TopDownDP_PermuteCoinChanges(int amount)
{
	int dp[N];
	const int coinCount = 4;
	int coin[coinCount] = { 2,3,5,6 };

	for (int i = 0; i < N; dp[i++] = MIN);
	//for (int i = 0; i < M; coin[i++] = MIN);

	// Base case -- no coin required for 0.
	dp[0] = 1;

	// Go over all the amounts upto N, storing the maximum
	for (int j = 0; j < coinCount; j++)
	{
		for (int i = coin[j]; i <= amount; i++)
		{
			if (i <= coin[j])
			{
				if (dp[i - coin[j]] != MIN)
				{
					// That means we can add coins[j] to get the sum i. 
					dp[i] += dp[i - coin[j]];
				}
			}
		}
	}
	// 
	return dp[amount];
}


int BottomUp_PermuteCoinChanges(int desiredAmount, int coins[], int numberOfCoins)
{
	// dp[i] is number of ways to compose 'i' amount, including 0
	int* dp = new int[desiredAmount + 1];
	
	for (int i = 0; i < desiredAmount + 1; dp[i++] = 0);

	dp[0] = 1; // There's a one way to compose 0 amount -- by choosing no coins
	
	// Pick all coins one by one and update the dp[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for (int i = 0; i<numberOfCoins; i++)
		for (int j = coins[i]; j <= desiredAmount; j++)
			dp[j] += dp[j - coins[i]];

	return dp[desiredAmount];
}

void PrintRhombus()
{
	int n;
	cin >> n;
	for (int i = n -1 ; i >= 0; i--)
	{
		// print leading spaces
		int j = i;
		while (j--) { cout << " "; }
		cout << "*";
		j = n - 2;
		while (j--)
		{
			if (i == 0 || i == n-1)
				cout << "*";
			else 
				cout << " ";
		}
		cout << "*" << endl;
	}
}

void ExecCoinChange()
{
	PrintRhombus();

	/*
	int amount = 10;
	int denominationCount = 4;
	cin >> amount >> denominationCount;
	cin.ignore();
	int * denominations = new int[denominationCount]; // { 2, 3, 5, 6 };
	for (int i = 0; i < denominationCount; i++)
	{
		cin >> denominations[i];
	}
	
	int waysToChange = 0;
	
	waysToChange = BottomUp_PermuteCoinChanges(amount, denominations, denominationCount);
	cout << waysToChange << endl;
	*/
}
