#include <bits/stdc++.h>
using namespace std;

//TC = O(n) , SC = O(n)

int longestSubsequence(int n, int *arr)
{
    int ma = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        if (mp[arr[i] - 1])
            a = mp[arr[i] - 1];
        if (mp[arr[i] + 1] and mp[arr[i] + 1] > a)
            a = mp[arr[i] + 1];

        mp[arr[i]] = a + 1;
        ma = max(ma, mp[arr[i]]);
    }
    return ma;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSubsequence(n, arr) << endl;
}

/*

//TC = O(n^2) , SC = O(n)

int longestSubsequence(int n, int *arr)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp,dp+n);
}
*/
