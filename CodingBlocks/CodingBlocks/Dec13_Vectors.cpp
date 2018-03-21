#include "stdafx.h"

#include <vector>

//
//void 
//VectorPractice()
//{
//	int n;
//	cout << "enter vector size" << endl;
//	cin >> n;
//
//	vector<int> v; // give initial len as twice of expected elements so we can avoid expensive expansion
//	for (int i = 0; i <= n; i++)
//	{
//		v.push_back(i * i); 
//		cout << i << " curr size" << v.size() << " max capacity " << v.max_size() << endl;
// 	}
//}
//

bool Comparator(string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	else //if (a.length > b.length)
	{
		return a > b;
	}
	//else
	//{
	//	int i;
	//	while (a[i] == b[i++]);
	//	return a[i] < b[i];

	//}

}


void 
SortStrings()
{
	int n; 
	cout << "Enter number of strings to read";
	cin >> n;
	char s[3][10] = {"ape", "apple", "mango"};


	vector<string> v(n);
	while (n--)
	{
		
	}

}