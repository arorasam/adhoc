#pragma once

int min(int a, int b);// { return a > b ? b : a; }
int max(int a, int b);// { return a > b ? a : b; }

void ExecTowerOfHanoi();
int TowersOfHanoi(int n, char src, char tgt, char helper);


void ExecPrintStringPerms();
void PrintStringPerms(const char* str, bool availableOptions[], int len, int currIdx);
int  PrintStringPerms_InClass(char *a, int i);


void FindFirstOccurrenceInSortedArray(int arr[], int len, int x);
//void FindSquaRootWithPrecision(int arr[], int preicision);

//void VectorPractice();
int MinPeopleSamedayBirthday();

void ExecPhoneKeyPadStrings();
void PhoneKeyPadStrings(string *keypad, char* in, char* out, int i, int j);


void ExecReplacePi();
void ReplacePi(char* arr, int len);


void ExecSudoku();


// Coin Change
void ExecCoinChange();
bool Recursive_PermuteCoinChanges(int remainingAmount, int denominations[], int denominationCount, int &waysToChange);

// Grand Temple
void Exec_DetermineBiggestTempleSite();
//int DetermineBiggestTempleSite(vector<int> Xes, vector<int> Ys, int numOfPoints);


void Exec_GermanLotto();

void Exec_MinimizeTowerHeightDifference();

void Exec_CheckSumString();

void Exec_MinTrialsToDeterminePlateBreakageHeight(); 


void Exec_Merge();

void Exec_Tree();

void Exec_PrintSubsequences();
