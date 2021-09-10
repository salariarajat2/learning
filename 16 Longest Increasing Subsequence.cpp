#include <bits/stdc++.h>
using namespace std;

//TC = O(n logn) , SC = O(N)

int longestSubsequence(int n, int *a)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = INT_MAX;
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int up = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (dp[up] > a[i] and dp[up - 1] < a[i])
        {
            dp[up] = a[i];
        }
    }
    int m = 0;
    for (int i = n; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
        {
            m = i;
            break;
        }
    }
    return m;
}

int main()
{
    int N = 6;
    int A[] = {5, 8, 3, 7, 9, 1};
    cout << longestSubsequence(N, A);
}

/*

//TC = O(N^2) , SC = O(N)

int longestSubsequence(int n, int *a)
{
    int arr[n] = {1};
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
    }
    return *max_element(arr, arr + n);
}
*/
