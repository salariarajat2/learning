#include <bits/stdc++.h>
using namespace std;

//TC = O(N^2), SC = O(N^2)

int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    string ans = "";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (str[i - 1] == str[j - 1] and i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    
    int i = n, j = n;
    while (i > 0 and j > 0)
    {
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            ans = ans + str[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return dp[n][n];
}
int main()
{
    string str = "AABEBCDD";
    cout << findLongestRepeatingSubSeq(str);
    return 0;
}
