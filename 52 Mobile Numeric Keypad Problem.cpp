#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC= O(n)

long long dp[10][1005];
int mat[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

long long func(int i, int j, int n)
{
    if (n == 1)
        return 1;
    if (dp[mat[i][j]][n] != -1)
        return dp[mat[i][j]][n];
    long long a = func(i, j, n - 1);

    long long b, c, d, e;
    b = c = d = e = 0;
    if (i - 1 >= 0 and mat[i - 1][j] != -1)
        b = func(i - 1, j, n - 1);
    if (i + 1 < 4 and mat[i + 1][j] != -1)
        c = func(i + 1, j, n - 1);
    if (j - 1 >= 0 and mat[i][j - 1] != -1)
        d = func(i, j - 1, n - 1);
    if (j + 1 < 3 and mat[i][j + 1] != -1)
        e = func(i, j + 1, n - 1);

    return dp[mat[i][j]][n] = b + c + d + e + a;
}
long long getCount(int N)
{
    dp[10][N + 1];
    memset(dp, -1, sizeof(dp));
    long long a = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] != -1)
                a += func(i, j, N);
        }
    }
    return a;
}

int main()
{
    int n = 2;
    cout << getCount(n);
}
// Output: 36
