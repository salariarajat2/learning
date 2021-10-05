
#include <iostream>
using namespace std;

// The time and space complexity is O(n) and O(1)   // valley-peak approach

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = 7;
    int profit = 0;
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        s = price[i] - price[i - 1];
        if (s > 0)
            profit += s;
    }
    cout << profit;
}

/*

int maxProfit(int price[], int n)
{
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;

    int ma = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > ma)
            ma = price[i];
        dp[i] = max(dp[i + 1], ma - price[i]);
    }

    int mi = price[0];
    for (int i = 1; i < n; i++)
    {
        if (price[i] < mi)
            mi = price[i];
        dp[i] = max(dp[i - 1], dp[i] + (price[i] - mi));
    }

    int a = dp[n - 1];
    delete[] dp;
    return a;
}

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}
*/