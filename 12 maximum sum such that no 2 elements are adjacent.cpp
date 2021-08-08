#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

int dp[10001];
int aa(int *arr, int n)
{
    if (n <= -1)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int a = arr[n] + aa(arr, n - 2);
    int b = aa(arr, n - 1);

    return dp[n] = max(a, b);
}

int main()
{
    int n;
    cin >> n;
    dp[n];
    memset(dp, -1, sizeof(dp));
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << aa(arr, n - 1);
}





/*
int FindMaxSum(vector<int> arr, int n)
{
    int idx = arr[0];
    int csum = 0;
    int mx;

    for (int i = 1; i < n; i++)
    {
        mx = (idx > csum) ? idx : csum;
        idx = csum + arr[i];
        csum = mx;
    }
    return ((idx > csum) ? idx : csum);
}

int main()
{
    vector<int> arr = {5, 5, 10, 40, 50, 35} ;
    cout << FindMaxSum(arr, arr.size());
}
*/
