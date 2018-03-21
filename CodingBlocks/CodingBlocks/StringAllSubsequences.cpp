#include "stdafx.h"
#include <stack>
#define MAXLEN 10000
/*Take as input str, a string.We are concerned with all the possible subsequences of str.E.g.
a.Write a recursive function which returns the count of subsequences for a given string.Print the value returned.

b.Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences 
  “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.
  given string(void is the return type for function).
*/


void PrintSubsequences(char* in, char * out, int inIdx, int outIdx, stack<char*>& stk)
{
	if (in[inIdx] == '\0')
	{
		out[outIdx] = '\0';
		size_t x = strlen(out);
		char * temp = new char(x+1);
		strcpy_s(temp, x + 1,  out);
		stk.push(temp);
		return;
	}

	out[outIdx] = in[inIdx];
	PrintSubsequences(in, out, inIdx + 1, outIdx + 1, stk);
	PrintSubsequences(in, out, inIdx + 1, outIdx, stk);
}


void Exec_PrintSubsequences()
{
	int count = 0;
	char input[MAXLEN];

	stack<char*> stk;
	cin >> input;
	int len = strlen(input);
	char * out = new char(len);
	PrintSubsequences(input, out, 0, 0, stk);

	count= stk.size();
	cout << count << endl;
	while (!stk.empty())
	{
		char * temp = stk.top();
		cout << temp << " ";
		stk.pop();
	}
}
