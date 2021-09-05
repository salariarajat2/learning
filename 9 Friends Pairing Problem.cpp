#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Auxiliary Space: O(n)

int mod = pow(10, 9) + 7;

int iter(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1]) % mod + ((i - 1) % mod) * dp[i - 2] % mod) % mod;
    }
    return dp[n];
}

int main()
{
    int n = 4;
    cout << iter(n);
}

/*

long long int func(int n, long long int *dp)
{
    if (n <= 2)
        return n;
    if (dp[n] != -1)
        return dp[n];

    int a = ((n - 1) % mod * func(n - 2, dp) % mod) % mod;
    int b = func(n - 1, dp) % mod;

    return dp[n] = a + b;
}

int main()
{
    int N = 4;
    long long int dp[N + 1];
    memset(dp, -1, sizeof(dp));
    cout << func(N, dp) % mod;
}
*/

