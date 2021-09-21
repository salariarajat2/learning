#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC= O(n)

bool findWinner(int x, int y, int n)
{
    bool dp[n + 1];
    dp[0] = false;
    dp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;
        else
            dp[i] = false;
    }
    return dp[n];
}

int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}

/*
ans = A
*/
