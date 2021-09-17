#include <bits/stdc++.h>
using namespace std;

// TC = O(n logn), SC = O(1)

int main()
{
    int k = 4;
    int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int ans = n - 1;
    for (int i = 0; i < n; i++)
    {
        int a = upper_bound(arr + i, arr + n, arr[i] + k) - arr - 1;
        ans = min(ans, n - (a - i + 1));
    }
    cout << ans;
    return 0;
}

/*
//TC = O(n^2), SC = O(n^2)

int dp[1001][1001];

int func(int *arr, int n, int m, int k)
{
    if (n >= m)
        return 0;
    if (arr[m] - arr[n] <= k)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    return dp[n][m] = 1 + min(func(arr, n + 1, m, k), func(arr, n, m - 1, k));
}

int main()
{
    int k = 4;
    int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    sort(arr, arr + n);
    cout << func(arr, 0, n - 1, k);
    return 0;
}


ans = 5
*/
