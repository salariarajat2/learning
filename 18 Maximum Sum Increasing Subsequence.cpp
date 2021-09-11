#include <bits/stdc++.h>
using namespace std;

//TC = O(n^2) , SC = O(n)

int maxSumIS(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main()
{
    int N = 5, arr[] = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr, N);
}

