// In the begining of his life, Alan Turing(A great Computer Scientist and mathematician) had made a machine which read the number from a given sequence.The numbers are written in a particular order such that each number is equal to the sum of two preceding numbers(except first and second).All the numbers of that sequence is combined together and didn't separated by any comma or space.
// Example : 12 12 24 36 60 is that kind of sequence. 1212243660 is read by Turing machine which return true as each number is equal to the sum of two preceding numbers.Similarly 12 012 24 36 60 is also that kind of sequence.Hence 12012243660 will give true value.
// You work is to find either written numbers will give true or false.

#include "stdafx.h"

bool CheckSumString(char* arr, int len, int startingDigitCount)
{
	// for each digit count lenght from startingDigitCount to len-1
	// 1. Parse initial number
	// Algo: If past two numbers add upto current number or if current number satisfies supplied two numbers, then this is a
	// correct triplet. Return true and move the pointer to the end of current 

	return false;
}

void
Exec_CheckSumString()
{
	char arr[] = "12012243660";
}