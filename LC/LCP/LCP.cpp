// LCP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		map<int, int>::iterator m_iter_1, m_iter_2;
		int idx = 0;
		vector<int>* result = new vector<int>(2);

		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
			if (m.find(*iter) == m.end())
			{
				m[*iter] = idx++;
			}
			else if (m.find(target - *iter) != m.end())
			{
				m_iter_1 = m.find(*iter);
				m_iter_2 = m.find(target - *iter);
				// check if both numbers exist
				result->push_back(m_iter_1->second);
				result->push_back(m_iter_2->second);

			}
		}

		return *result;
	}
};

int main()
{
	cout << "Enter list of numbers";

	return 0;
}
