#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int jobsheduling(vector<int> &st, vector<int> &et, vector<int> &profit)
{
    int n = st.size();
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x = st[i];
        int y = et[i];
        int z = profit[i];
        v[i] = {x, y, z};
    }

    sort(v.begin(), v.end(), comp);
    int dp[n];
    dp[0] = v[0][2];

    for (int i = 0; i < n; i++)
    {
        int inc = v[i][2];
        int last = -1;
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid][1] <= v[i][0])
            {
                last = mid + 1;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (last != -1)
            inc += dp[last];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> st(n);
	vector<int> et(n);
	vector<int> profit(n);
    for (int i = 0; i < n; i++)
        cin >> st[i];
    for (int i = 0; i < n; i++)
        cin >> et[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << jobsheduling(st, et, profit);
}

/*
4
3 1 6 2
10 2 19 100
20 50 100 200

ans= 250;

*/


