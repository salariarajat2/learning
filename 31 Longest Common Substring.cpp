#include <bits/stdc++.h>
using namespace std;

//TC = O(n*m), SC = O(n*m)

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    int dp[n + 1][m + 1];
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    string S1 = "ABCDGH", S2 = "ACDGHR";
    cout << longestCommonSubstr(S1, S2, S1.length(), S2.length());
    return 0;
}

/*
ans = 4
*/
