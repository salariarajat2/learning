#include <bits/stdc++.h>
using namespace std;

//TC = O(N log n), SC = O(1)

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxChainLen(vector<pair<int, int>> v, int n)
{
    sort(v.begin(), v.end(), comp);
    int i = 0, j = 1, c = 1;
    while (j < n)
    {
        if (v[i].second < v[j].first)
        {
            c++;
            i = j;
            j++;
        }
        else
            j++;
    }

    return c;
}

int main()
{
    int N = 5;
    vector<pair<int, int>> v = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(v, N);
    return 0;
}

/*ans =  3


//TC = O(N^2), SC = O(n)

int maxChainLen(vector<pair<int, int>> v, int n)
{
    sort(v.begin(), v.end());
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j].second < v[i].first)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + n);
}
*/
