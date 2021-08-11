#include <bits/stdc++.h>
using namespace std;

//time complexity- O(log N)

bool solve(int *arr, int n, int m, int mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            sum += arr[i] - mid;
    }

    if (sum >= m)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int h = *max_element(arr, arr + n);
    int ans = 0;
    int l = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (solve(arr, n, m, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans;
}



/*
4 7
20 15 10 17


ans-   15
*/




