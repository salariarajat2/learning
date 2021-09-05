#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*s/2), Auxiliary Space: O(N*s/2)

int dp[1000][1000];

int fun(int n, int *arr, int s)
{
    if (n == -1)
    {
        if (s == 0)
            return 1;
        return 0;
    }
    if (s < 0)
        return 0;
    if (s == 0)
        return 1;
    if (dp[n][s] != -1)
        return dp[n][s];
    return dp[n][s] = fun(n - 1, arr, s - arr[n]) || fun(n - 1, arr, s);
}

int equalPartition(int n, int arr[])
{
    int s = 0;
    s = accumulate(arr, arr + n, 0);
    if (s & 1)
        return 0;
    s /= 2;
    dp[n][s];
    memset(dp, -1, sizeof(dp));
    return fun(n - 1, arr, s);
}

int main()
{
    int N = 4;
    int arr[] = {1, 5, 11, 5};
    (equalPartition(N, arr)) ? cout << "YES" : cout << "NO";
}

