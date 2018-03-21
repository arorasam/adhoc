#include "stdafx.h"
#include <sstream>
void ExecReplacePi()
{
	char testCase[MAX_STR_LEN];
	int testCaseCount;
	cin >> testCaseCount;
	cin.ignore();
	for (int i = 0; i < testCaseCount; i++)
	{
		cin.getline(testCase, MAX_STR_LEN);

		ReplacePi(testCase, strlen(testCase));
		cout << testCase << endl;
	}
}

void ReplacePi(char* arr, int len)
{
	// Assuming arr has enough space to expand
	// read backwards and replace when encountering 41.3 
	if (len < 4)
		return;
	int index = 0;
	for (int i = 0; i < len;)
	{
		if (arr[i] == '3' && arr[i + 1] == '.' && arr[i + 2] == '1' && arr[i + 3] == '4')
		{
			arr[index++] = 'p';
			arr[index++] = 'i';
			i += 4;
		}
		else
		{
			arr[index++] = arr[i++];
		}
	}

	arr[index] = '\0';
}