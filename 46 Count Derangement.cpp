#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC= O(1)

int solve(int n)
{
    int a = 0, b = 1;

    for (int i = 3; i <= n; i++)
    {
        int z = (i - 1) * (a + b);
        a = b;
        b = z;
    }
    return b;
}

int main()
{
    int n = 4;
    cout << solve(n);
    return 0;
}

/*9

// TC = O(n) , SC= O(n)

int solve(int n)
{
    int dp[n + 1] = {0};
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}


// TC = O(exponential) , SC= O(1)

int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return (n - 1) * (solve(n - 1) + solve(n - 2));
}

*/
