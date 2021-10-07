#include <bits/stdc++.h>
using namespace std;

//Part 2 = Each student should be awarded with at least one chocolate
// A student with higher marks should be awarded more chocolates than his adjacent students.
//TC = O(N), SC= O(1)

int get_sum(int peak, int start, int end)
{
    int count = end - start + 1;
    peak = (peak > count) ? peak : count;
    int s = peak + (((count - 1) * count) >> 1);
    return s;
}

int minChocolates(int a[], int n)
{
    int i = 0, j = 0;
    int res = 0, val = 1;

    while (j < n - 1)
    {

        if (a[j] > a[j + 1])
        {
            j += 1;
            continue;
        }

        if (i == j)
            res += val;
        else
        {
            res += get_sum(val, i, j);
            val = 1;
        }

        if (a[j] < a[j + 1])
            val += 1;
        else
            val = 1;

        j += 1;
        i = j;
    }
    if (i == j)
        res += val;
    else
        res += get_sum(val, i, j);

    return res;
}

int main()
{
    int A[] = {23, 14, 15, 14, 56, 29, 14};
    int N = sizeof(A) / sizeof(A[0]);

    cout << minChocolates(A, N);
}

/*
// TC = O(n), SC = O(n)


void minChocolates(int a[], int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            arr[i] = max(arr[i + 1] + 1, arr[i]);
        else
            arr[i] = max(arr[i], 1);
    }

    int sum = accumulate(arr, arr + n, 0);
    cout << sum << "\n";
}
*/

/*

Part 1 // when there are m no. of students



//TC = O(nlogn), SC = O(1)

int func(int *arr, int n, int m)
{
    sort(arr, arr + n);
    int ans = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        ans = min(ans, arr[i + m - 1] - arr[i]);
    }
    return ans;
}


//TC = O(n^2) , SC = O (1) //two for loops find smallest sum subarray
*/
