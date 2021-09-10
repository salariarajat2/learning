#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Auxiliary Space: O(n)

int dp[10005];

int func(int n, int x, int y, int z)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int a, b, c;
    a = b = c = INT_MIN;

    if (n >= x)
        a = func(n - x, x, y, z);
    if (n >= y)
        b = func(n - y, x, y, z);
    if (n >= z)
        c = func(n - z, x, y, z);

    return dp[n] = 1 + max(a, max(b, c));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    memset(dp, -1, sizeof(dp));
    int a = func(n, x, y, z);
    if (a < 0)
        return 0;
    return a;
}

int main() 
{
    int N = 4;
    int x = 2, y = 1, z = 1;
    cout << maximizeTheCuts(N, x, y, z);
}
