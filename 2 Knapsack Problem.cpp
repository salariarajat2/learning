#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(w*n), Auxiliary Space: O(w*n)

int dp[1000][1000];

int solve(int *val, int *wt, int w, int n)
{
    if (n < 0 or w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n] > w)
        return dp[n][w] = solve(val, wt, w, n - 1);

    int a = val[n] + solve(val, wt, w - wt[n], n - 1);
    int b = solve(val, wt, w, n - 1);
    return dp[n][w] = max(a, b);
}

int knapSack(int W, int wt[], int val[], int n)
{
    dp[n][W + 1];
    memset(dp, -1, sizeof(dp));
    return solve(val, wt, W, n - 1);
}

int main()
{
    int N = 3, W = 4;
    int values[] = {1, 2, 3}, weight[] = {4, 5, 1};
    cout << knapSack(W, weight, values, N);
}

