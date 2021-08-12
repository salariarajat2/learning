#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity: O(N^2)
	Space Complexity: O(N),
    quick sort approach
*/

void quickSort(vector<int> &arr, int low, int high)
{

	if (low >= high)
	{
		return;
	}

	int pivot = arr[high];

	int small = low, j = low;

	while (small < high)
	{
		if (arr[small] <= pivot)
		{
			swap(arr[small], arr[j]);
			j++;
		}
		small++;
	}

	swap(arr[high], arr[j]);

	quickSort(arr, low, j - 1);

	quickSort(arr, j + 1, high);
}

vector<int> sortArray(vector<int> &arr)
{
	quickSort(arr, 0, arr.size() - 1);

	return arr;
}





/*
Dijkstra’s Dutch National Flag(DNF)
    Time Complexity: O(N^2)
    Space Complexity: O(N)

*/

void quickSortHelper(vector<int> &arr, int beg, int last, int &start, int &mid)
{
	int pivot = arr[last];
	int end = last;

	// Iterate while mid is not greater than end.
	while (mid <= end)
	{
		// Place the element at the starting if it's value is less than pivot.
		if (arr[mid] < pivot)
		{
			swap(arr[mid], arr[start]);
			mid = mid + 1;
			start = start + 1;
		}

		// Place the element at the end if it's value is greater than pivot.
		else if (arr[mid] > pivot)
		{
			swap(arr[mid], arr[end]);
			end = end - 1;
		}

		else
		{
			mid = mid + 1;
		}

	}

}

// An auxiallary function to sort the array.
void quicksort(vector<int> &arr, int beg, int last)
{
	// Base case when the size of array is 1.
	if (beg >= last)
	{
		return;
	}

	int start = beg, mid = beg;
	// Function to partition the array.
	quickSortHelper(arr, beg, last, start, mid);

	// Recursively sort the left and the right partitions
	quicksort(arr, beg, start - 1);
	quicksort(arr, mid, last);

}

vector<int> sortArray(vector<int> &arr)
{
	// Call the quicksort function.
	quicksort(arr, 0, arr.size() - 1);

	// Return the array after sorting
	return arr;
}
