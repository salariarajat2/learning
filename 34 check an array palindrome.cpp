#include <bits/stdc++.h>
using namespace std;

//if we have to check the value at index is palindrome

int a(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int res = 0;
		int temp = arr[i];

		while (temp > 0)
		{
			int r = temp % 10;
			temp /= 10;
			res = (res * 10) + r;
		}
		if (res != arr[i])
			return 0;
	}
	return 1;
}

int main()
{

	int n;
	cin >> n;
	int i, arr[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << a(arr, n);
}

/*
//for single elements

int palindrome(int arr[], int n)
{
    for (int i = 0; i <= n / 2 and n != 0; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
*/