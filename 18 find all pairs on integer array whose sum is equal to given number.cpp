#include <bits/stdc++.h>
using namespace std;

// TC = O(n), SC = O(n)

int getPairsCount(int *arr, int n, int k)
{
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.count(k - arr[i]))
        {
            mp[arr[i]]--;          //freaquecy of ith element decreses by 1 because it make pair
            ans += mp[k - arr[i]]; //frequency of element who make pair with ith element to give complete sum like 5
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << getPairsCount(arr, n, k) << endl;
    }

    return 0;
}

/*
// Time Complexity: O(n2), Auxiliary Space: O(1)
 
int getPairsCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;
 
    return count;
}
*/
