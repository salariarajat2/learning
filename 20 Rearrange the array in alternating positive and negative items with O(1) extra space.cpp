#include <bits/stdc++.h>
using namespace std;

//TC = O(n), SC = O(1)

void rearrange(int arr[], int n)
{
	int i = 0, j = n - 1;
	while (i <= j)
	{
		if (arr[i] < 0 and arr[j] > 0)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else if (arr[i] > 0 and arr[j] < 0)
		{
			i++;
			j--;
		}
		else if (arr[i] > 0)
		{
			i++;
		}
		else if (arr[j] < 0)
		{
			j--;
		}
	}

	if (i == 0 || i == n)
		return;
	else
	{
		int k = 0;
		while (k < n && i < n)
		{
			swap(arr[k], arr[i]);
			i++;
			k = k + 2;
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {2, 3, -4, -1, 6, -9};

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}

/*

void rearrange(int arr[], int n)
{
    int i = 0, j = n-1;
    // shift all negative values to the end
    while (i < j)
    {
        while(i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j)
            swap(arr[i], arr[j]);
    }
 
    if (i == 0 || i == n)
        return;

    int k = 0;
    while (k < n && i < n)
    {
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}



TC = O(n) , SC = O(N) + O(N) + O(N) //use one for -ve and one for +ve values

*/

