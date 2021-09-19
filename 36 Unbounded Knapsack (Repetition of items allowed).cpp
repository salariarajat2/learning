#include <bits/stdc++.h>
using namespace std;

// TC = O(n*w) , SC= O(n*w)

int dp[1005][1005];

int func(int n, int w, int *val, int *wt)
{
    if (n <= -1)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (w < wt[n])
        return dp[n][w] = func(n - 1, w, val, wt);
    int a = func(n - 1, w, val, wt);
    int b = val[n] + func(n, w - wt[n], val, wt);

    return max(a, b);
}

int knapSack(int N, int W, int val[], int wt[])
{
    dp[N][W];
    memset(dp, -1, sizeof(dp));
    return func(N - 1, W, val, wt);
}

int main()
{
    int N = 4, W = 8;
    int val[] = {1, 4, 5, 7}, wt[] = {1, 3, 4, 5};
    cout << knapSack(N, W, val, wt);
}

/*
ans = 11
*/
