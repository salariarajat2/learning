#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        mp[pre]++;
    }

    map<int, int>::iterator it;
    int ans = 0;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        int c = it->second;

        ans += (c * (c - 1)) / 2;
        if (it->first == 0)
            ans += it->second;
    }
    
    cout<<ans;
    
for(auto a : mp)
{
	cout<<a.first<<"  "<<a.second<<endl;
}
}







/*

//Time Complexity: O(n), Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int aa(long long int *arr, int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
        if (sum == 0)//for current subarray 
        {
            count++;
        }
        if (mp.find(sum) != mp.end())//combination of previous subarray which can make value zero
        {
            count += mp[sum];
        }
        mp[sum]++;
    }
    return count;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << aa(arr, n) << "\n";
    }
    return 0;
}
*/

