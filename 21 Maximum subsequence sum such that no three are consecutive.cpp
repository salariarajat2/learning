#include <bits/stdc++.h>
using namespace std;

//TC = O(N), SC = O(n)

int dp[10000];

int func(int *arr, int n)
{
    if (n == -1)
        return 0;
    if (n == 0)
        return arr[0];
    if (n == 1)
        return arr[0] + arr[1];
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(max(func(arr, n - 1), arr[n] + func(arr, n - 2)), arr[n] + arr[n - 1] + func(arr, n - 3));
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << func(arr, n - 1);

    return 0;
}

/*
5
100 1000 100 1000 1
2101
*/
