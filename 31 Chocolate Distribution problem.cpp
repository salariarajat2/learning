#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++)
        {
            diff = min(diff, arr[i + m - 1] - arr[i]);
        }

        cout << diff;
    }
    return 0;
}






/*
long long v[10000004];
int main()
{
        long long n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long m;
        cin >> m;
        sort(v, v + n);
        long long diff = INT_MAX;
        for (int i = m - 1; i < n; i++)
        {
            diff = min(diff, v[i] - v[i - m + 1]);
        }
        cout << diff << endl;
    return 0;
}
*/
