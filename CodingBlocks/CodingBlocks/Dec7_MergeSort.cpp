#include "stdafx.h"
static int inversionCount = 0;
static int inversionCount2 = 0;
static int inversionCount3 = 0;

int Merge(int arr[], int l, int m, int r)
{
	int i,  j , ll = 0;
	int leftElements = m - l + 1; // include 'm' as well in this range
	int rightElements = r - m;
	int* L = new int[leftElements];
	int* R = new int[rightElements];

	// Copy arr elements to into sub halves. 
	for (int i = 0; i < leftElements; i++) { L[i] = arr[l + i]; }
	for (int i = 0; i < rightElements; i++) { R[i] = arr[m + 1 + i]; }

	i = j = 0 ;
	ll = l;

	int invCount = 0;
	while (i < leftElements && j < rightElements)
	{
		
		if (L[i] <= R[j])
		{
			cout << "Copying from Left - " << L[i] << " onto index " << ll << endl;
			arr[ll++] = L[i++];
			inversionCount2++;
		}
		else
		{
			cout << "Copying from Right - " << R[j] << " onto index " << ll << endl;
				inversionCount3++;

			invCount += m - i;
			cout << "invCount: " << invCount << " inversionCount3: " << inversionCount3 << endl;
			arr[ll++] = R[j++];
			inversionCount++;
		}
	}

	// Copy remaining elements
	while (i < leftElements)
	{
		cout << "Mass-Copying from Left - " << L[i] << " onto index " << ll << endl;
		arr[ll++] = L[i++];
		//inversionCount++;
//		inversionCount3++;
	}
	while (j < rightElements)
	{
		cout << "Mass-Copying from Right - " << R[j] << " onto index " << ll << endl;
		arr[ll++] = R[j++];
	}

	delete[] R;
	delete[] L;

	return invCount;
}

int GFG_merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			/*this is tricky -- see above explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
	(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int MergeAuxSpace(int arr[], int temp[], int l, int m, int r)
{

	// Sort between l and r in store in temp.
	// Then copy temp[0..l-r+1] to arr[l..r]
	int i = l, j = m, k = 0;
	int invCount = 0;
	while (i <= m - 1 && j <= r)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			invCount += m - i;
		}
	}

	while (i <= m )
		temp[k++] = arr[i++];

	while (j <= r)
		temp[k++] = arr[j++];

	for (int x = l, y = 0; x <= r; x++, y++)
		arr[x++] = temp[y++];

	return invCount;
}

int mergeCount(int * arr, int s, int e)
{
	int  i = s; 
	int  mid = (s + e) / 2;
	int j = mid + 1;
	int k = s;
	// TODO
	int invCount = 0;
	while (i <= mid && j < e && arr[i++] <= arr[j++]);


	return invCount = mid - i;
}

int CountInversionsWhileMerging(int *arr, int i, int j)
{
	if (i >= j)
		return 0;

	int mid = (i + j) / 2;
	int temp[1000];
	int ret = CountInversionsWhileMerging(arr, i, mid) +
		CountInversionsWhileMerging(arr, mid + 1, j) +
		//MergeAuxSpace(arr, temp, i, mid + 1, j); // mergeCount(arr, i, mid);
		GFG_merge(arr, temp, i, mid + 1, j);
	return ret;
}

int 
MergeSort(int arr[10], int l, int r)
{
	int invCount = 0;
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		invCount += MergeSort(arr, l, mid);
		invCount += MergeSort(arr, mid + 1, r);
		invCount += Merge(arr, l, mid, r);
	}

	return invCount;
}

void 
Exec_Merge()
{
	int N;
	cin >> N;
	cin.ignore();
	int *arr = new int[N];
	int invCount = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; // arr[i];
	}

	invCount = CountInversionsWhileMerging(arr, 0, N - 1); // MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "inversionCount:" << inversionCount << " inversionCount2: " << inversionCount2 << " inversionCount3: " << inversionCount3 << " invCount:" << invCount << endl;
}