#include "stdafx.h"
#include <set>

static int counter;
void ExecPrintStringPerms()
{
	char arr[100];
	cout << "Enter a string to permute" << endl;

	cin >> arr;
	set<string> s;
	s.insert(arr);

	//PrintStringPerms(arr, boolArr, strlen(arr), 0);
	int count = PrintStringPerms_InClass(arr, 0);
	cout << count << " permutations" << endl;
}


int PrintStringPerms_InClass(char *a, int i)
{
	int result = 0;
	// Base case, stop when reached end of string.
	if (a[i] == '\0')
	{
		cout << "---" << endl;
		cout << a << endl;
		return 1 ;
	}

	// Place one char at the front and cball the remaining part
	for (int j = i; a[j] != '\0'; j++)
	{
		//if (i != j)
		{
			cout << "i: " << i << " j: " << j << endl;
			swap(a[i], a[j]);
			result += PrintStringPerms_InClass(a, i+1);
			// Restore to backtrack
			swap(a[j], a[i]);
		}
	}

	return result;
}

void PrintStringPerms(const char* str, bool availableOptions[], int len, int currIdx)
{
	//ToDo: Use Bitmask instead of bool array

	// terminating condition
	if (str[currIdx] == '\0')
	{
		// assuming str remains null terminated across recursive calls
		cout << endl;
	}
	
	// Real Work -- chose next character from available options
	for (int i = 0; i < len; i++)
	{
		if (availableOptions[i])
		{
			cout << str[i];
			availableOptions[i] = false;
			PrintStringPerms(str, availableOptions, len, currIdx + 1);
			availableOptions[i] = true;
		}
	}
	// recursive case

}