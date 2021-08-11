#include <bits/stdc++.h>
using namespace std;

bool solve(int *arr, int n, int par, int mid)
{
    int time = 0, pratha = 0;
    for (int i = 0; i < n; i++)
    {
        time = arr[i];
        int j = 2;
        while (time <= mid)
        {
            pratha++;
            time += (arr[i] * j);
            j++;
        }
        if (pratha >= par)
            return 1;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int par;
        cin >> par;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int lb = 0, ans = 0, ub = 1e8;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (solve(arr, n, par, mid))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        cout << ans;
    }
}
/*
2
10 4 1 2 3 4

ans= 12


8
8 1 1 1 1 1 1 1 1

ans=1
*/
