#include <bits/stdc++.h>
using namespace std;

//TC=O(n+m), SC = O(1)

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			cout << a[i++] << " ";
		}
		else if (b[j] < a[i])
		{
			cout << b[j++] << " ";
		}
		else if (b[j] == a[i])
		{
			cout << a[i] << " ";
			i++;
			j++;
		}
	}
	while (i < n)
	{
		cout << a[i++] << " ";
	}
	while (j < m)
	{
		cout << b[j++] << " ";
	}
}

/*

//TC=O(nlogn) + (mlogm)

int main()
{
	int x, y;
	cin >> x >> y;

	int arr1[x];
	int arr2[y];

	for (int i = 0; i < x; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < y; i++)
	{
		cin >> arr2[i];
	}

	for (int i = x - 1, j = 0; i >= 0 && j < y; i--, j++)
	{

		if (arr1[i] >= arr2[j])
		{
			swap(arr1[i], arr2[j]);
		}
		else
		{
			break;
		}
	}
	sort(arr1, arr1 + x);
	sort(arr2, arr2 + y);

	for (int i = 0; i < x; i++)
	{
		cout << arr1[i] << " ";
	}
	for (int i = 0; i < y; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "\n";
	return 0;
}

*/

/*
4 5
1 3 5 7
0 2 6 8 9
*/
