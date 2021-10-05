#include <bits/stdc++.h>
using namespace std;

//third approach ->TC= O(n) SC- O(n)

bool isSubset(int m, int n, int arr1[], int arr2[])
{
	unordered_map<int, int> mp;
	for (int i = 0; i < m; i++)
		mp[arr1[i]]++;

	for (int i = 0; i < n; i++)
	{
		if (mp.find(arr2[i]) == mp.end()) // if (!mp[arr2[i]])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		int arr1[m], arr2[n];
		for (int i = 0; i < m; i++)
			cin >> arr1[i];
		for (int i = 0; i < n; i++)
			cin >> arr2[i];

		if (isSubset(m, n, arr1, arr2))
			cout << "Yes" << endl;
		else
			cout << "No";
	}
	return 0;
}
/*
5
6 4	
11 1 13 21 3 7
11 3 7 1
*/

//ist approach   two for loop-> TC= O(n^2) SC- O(1)

//2ns approach sorting and two pointer-> TC- O(nlogn)  SC-> O(1)

/*
bool isSubset(int arr1[], int arr2[],int m, int n)
{
	int i = 0, j = 0;

	if (m < n)
		return 0;

	sort(arr1, arr1 + m);
	sort(arr2, arr2 + n);

	while (i < n && j < m)
	{
		if (arr1[j] < arr2[i])
			j++;
		else if (arr1[j] == arr2[i])
		{
			j++;
			i++;
		}
		else if (arr1[j] > arr2[i])
			return 0;
	}

	return (i < n) ? false : true;
}
*/