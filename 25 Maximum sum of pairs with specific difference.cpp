#include <bits/stdc++.h>
using namespace std;

//TC = O(N log n), SC = O(1)

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr + n, greater<int>());
    int sum = 0, i = 0;
    while (i < n - 1)
    {
        if (abs(arr[i] - arr[i + 1]) < k)
        {
            sum += arr[i] + arr[i + 1];
            i += 2;
        }
        else
        {
            i++;
        }
    }
    return sum;
}

int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumPairWithDifferenceLessThanK(arr, n, k);
    return 0;
}

/*
ans = 62
*/
