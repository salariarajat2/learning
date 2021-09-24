#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> ans, int n)
{
    unordered_map<int, int> mp;
    int s = 0, ma = 1;
    for (int i = 0; i < n; i++)
    {
        s += ans[i];
        if (s == 0)
        {
            ma = max(ma, i + 1);
        }
        else if (mp[s])
        {
            ma = max(ma, i - mp[s] + 1);
        }
        else
        {
            mp[s] = 1;
        }
    }
    return ma;
}

int func(int r, int c, vector<vector<int>> a)
{
    int ma = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        vector<int> ans(c);
        for (int j = i; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                ans[j] += a[j][k];
            }
            ma = max(ma, solve(ans, c) * (j - i + 1));
        }
    }
    return ma;
}

int main()
{
    int r=3,c=3;
    vector<vector<int>> a = {{1, 2, 3}, {-3, -2, -1}, {1, 7, 5}};
    cout<<func(r,c,a);
}
