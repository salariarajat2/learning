#include <bits/stdc++.h>
using namespace std;

// TC = O(n^2) , SC= O(n^2)

int dp[1005][1005];

int solve(string s, int i, int j)
{
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = 2 + solve(s, i + 1, j - 1);

    return dp[i][j] = max(solve(s, i + 1, j), solve(s, i, j - 1));
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, n - 1);
}

/*
13 
geeksforgeeks

ans = 5
*/
