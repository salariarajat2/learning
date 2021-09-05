#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m*n), Auxiliary Space: O(n).

int dp[1000][1000];

long long func(int *arr, int m, int n)
{
    if (m < 0 and n > 0)
        return 0;
    if (m >= 0 and n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = func(arr, m, n - arr[m]) + func(arr, m - 1, n);
}

long long count(int *arr, int m, int n)
{
    dp[m][n + 1];
    memset(dp, -1, sizeof(dp));
    return func(arr, m - 1, n);
}

int main()
{
    int n = 10, m = 4;
    int S[] = {2, 5, 3, 6};
    cout<<count(S,m,n);
}
