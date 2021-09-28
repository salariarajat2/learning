#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &v, int n, int k, double sm)
{
    sort(v.begin(), v.end());
    int ans = v[n - 1] - v[0];
    int mn = v[0] + k;
    int mx = v[n - 1] - k;
    if (mn > mx)
        swap(mn, mx);
    for (int i = 1; i < n - 1; i++)
    {
        int add = v[i] + k;
        int sub = v[i] - k;
        if (sub >= mn || add <= mx)
            continue;
        if (mx - sub <= add - mn)
            mn = sub;
        else
            mx = add;
    }
    ans = min(ans, mx - mn);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        vector<int> v(n);
        double sm = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sm += v[i];
        }
        func(v, n, k, sm);
    }
    return 0;
}