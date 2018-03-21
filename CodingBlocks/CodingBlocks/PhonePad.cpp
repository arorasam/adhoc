#include "stdafx.h"
#include <vector>

void PhoneKeysDictionaryWords(vector<string>& dictionary, string *keypad, char* in, char* out, vector<char*> wordDictionary, int i = 0, int j = 0)
{
	if (in[i] == '\0')
	{
		out[i] = '\0';
		// Iterate over string vector
		for (auto str : dictionary)
		{
			if(strstr())
		}

		cout << out << endl;
		return;
	}

	int digit = in[i] - '0';
	for (int k = 0; k < keypad[digit].length(); k++)
	{
		char ch = keypad[digit][k];
		out[j] = ch;
		PhoneKeysDictionaryWords(dictionary, keypad, in, out, i + 1, j + 1);
	}
}



void
ExecPhoneKeyPadStrings()
{
	// Define KeyPad as an array of strings
	string keypad[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	char out[100];

	char in[100];
	cout << "Enter a phone number: ";
	cin >> in;

	PhoneKeyPadStrings(keypad, in, out, 0, 0);
}

void PhoneKeyPadStrings(string *keypad, char* in, char* out, int i = 0, int j = 0)
{
	if (in[i] == '\0')
	{
		out[i] = '\0';

		cout << out << endl;
		return;
	}

	int digit = in[i] - '0';
	for (int k = 0; k < keypad[digit].length(); k++)
	{
		char ch = keypad[digit][k];
		out[j] = ch;
		PhoneKeyPadStrings(keypad, in, out, i + 1, j + 1);
	}
}

