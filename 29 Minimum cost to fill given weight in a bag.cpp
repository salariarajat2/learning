#include <bits/stdc++.h>
using namespace std;

//TC = O(n*w), SC = O(n*w)

int dp[1005][1005];

int func(int *arr, int n, int w)
{
    if (n <= -1 and w == 0)
        return 0;
    if (n <= -1)
        return 1e9;
    if (w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if ((n + 1) > w or arr[n] == -1)
        return dp[n][w] = func(arr, n - 1, w);
    int x = func(arr, n - 1, w);
    int y = arr[n] + func(arr, n, w - (n + 1));

    return dp[n][w] = min(x, y);
}

int minimumCost(int arr[], int n, int w)
{
    memset(dp, -1, sizeof(dp));
    int x = func(arr, n - 1, w);
    return (x >= 1e9) ? -1 : x;
}

int main()
{
    int n = 5, arr[] = {20, 10, 4, 50, 100};
    int w = 5;
    cout << minimumCost(arr, n, w);
    return 0;
}

/*
ans = 14
*/
