// CodingBlocks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }


int main()
{
	//ExecTowerOfHanoi();
	//ExecPrintStringPerms(); // Not DONE
	//MinPeopleSamedayBirthday();
	//ExecPhoneKeyPadStrings();
	//ExecReplacePi();
	// ExecSudoku(); // Not DONE
	//ExecCoinChange(); // Not DONE
	//Exec_DetermineBiggestTempleSite(); // Not DONE
	//Exec_GermanLotto();
	//Exec_MinimizeTowerHeightDifference();
	// Exec_CheckSumString();
	//Exec_MinTrialsToDeterminePlateBreakageHeight();
	//Exec_Merge();
	//Exec_Tree();

	Exec_PrintSubsequences();

	cout << endl;
	system("pause");

    return 0;
}

