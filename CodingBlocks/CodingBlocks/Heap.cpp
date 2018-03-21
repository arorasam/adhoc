#include "stdafx.h"
#include <vector>
#include <queue>
using namespace std;


class Person
{
public:
	string name;
	int money;
};

// Operator overloading
class PersonCompare
{
public:
	// Can be used as a functor
	bool operator()(Person a, Person b) {
		return a.money > b.money;
	}
};

class Heap {
	vector<int> v;


	// STL priority queue
	priority_queue<int> maxHeap; // default max heap
	priority_queue<Person, vector<Person>, PersonCompare > minHeap;

	bool minH;

	bool comp(int a, int b) {

		return minH ? a < b : a > b;
	}

	void Heapify(int index) {

		int left = 2 * index;
		int right = 2 * index + 1;
		int min_idx = index;

		if (left < v.size()  // left child exists
			&& comp(v[left], v[index]))
		{
			min_idx = left;
		}

		if (right < v.size()  // right child exists
			&& comp(v[right], v[index]))
		{
			min_idx = right;
		}

		if (index != min_idx) {
			swap(v[index], v[min_idx]);
		}

	}

public:
	Heap(int ds = 100, bool x = true) {
		v.reserve(ds);
		minH = x;

		// block the 0th index so we can have 1-based index
		v.push_back(-1);
	}


	void insert(int data) {

		v.push_back(data);
		int currentIndex = v.size() - 1;
		int parentIndex = currentIndex / 2;
		while (currentIndex > 1 && comp(v[currentIndex], v[parentIndex]))
		{
			swap(v[currentIndex], v[parentIndex]);
			currentIndex = parentIndex;
			parentIndex = parentIndex / 2;

		}
	}


	int top() { return v[1]; }

	void pop() {

		int last = v.size() - 1;
	}
};

//
//ostream& operator<<(ostream& a, ostream& b)
//{
//
//}