#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2), Auxiliary Space: O(n)

int lcs(int x, int y, string s1, string s2)
{
    int dp[2][y + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 or j == 0)
                dp[i % 2][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i % 2][j] = 1 + dp[(i + 1) % 2][j - 1];
            else
                dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
    }
    return dp[x % 2][y];
}

int main()
{

    int A = 3, B = 2;
    string str1 = "ABC", str2 = "AC";
    cout << lcs(A, B, str1, str2);
}

/*ans = 2

// Time Complexity: O(n^2), Auxiliary Space: O(n^2)

int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}


//recursion

int dp[1005][1005];

int func(int x, int y, string s, string sa)
{
    if (x == -1 or y == -1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (s[x] == sa[y])
        return dp[x][y] = 1 + func(x - 1, y - 1, s, sa);

    int a = func(x - 1, y, s, sa);
    int b = func(x, y - 1, s, sa);

    return dp[x][y] = max(a, b);
}
int lcs(int x, int y, string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    return func(x - 1, y - 1, s1, s2);
}
*/
