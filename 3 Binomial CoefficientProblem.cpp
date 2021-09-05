#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*r), Auxiliary Space: O(r)

int mod = pow(10, 9) + 7;

int nCr(int n, int r)
{
    if (n < r)
        return 0;
    if ((n - r) < r)
        r = n - r;
    int dp[r + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % mod;
        }
    }
    return dp[r];
}

int main()
{
    int n = 3, r = 2;
    cout << nCr(n, r);
}

