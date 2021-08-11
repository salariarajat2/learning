#include <bits/stdc++.h>
using namespace std;
void subset(int *arr, int st, int end, vector<int> &v1)
{
    int s = 0, n = end - st + 1;
    for (int i = 0; i < pow(2, n); i++)//pow(2,n) == (1<<n)
    {
        s = 0;
        int j = st;
        int x = i;
        while (x)
        {
            int l = x & 1;
            if (l)
                s += arr[j];
            j++;
            x = x >> 1;
        }
        v1.push_back(s);
    }
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v1, v2;

    subset(arr, 0, (n / 2) - 1, v1);
    subset(arr, (n / 2), n - 1, v2);

    sort(v2.begin(), v2.end());
    int count = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int lo = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        int hi = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        count += (hi - lo);
    }
    cout << count;
}

/*
3 -1 2
1 -2 3

ans= 5
*/
