#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ma = arr[0];
    int cnt = 1, nn = n / 2, cntt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == ma)
            cnt++;
        else
            cnt--;

        if (cnt == 0)
        {
            ma = arr[i];
            cnt = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ma == arr[i])
            cntt++;
    }
    if (cntt > nn) cout << ma;
    else
        cout<<"not present";
}










/*
//Time Complexity: O(n), Space Complexity: O(n)

int majorityElement(int arr[], int n)
{
    int aa = n / 2;
    unordered_map<int, int> a;

    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }

    for (auto it : a)
    {
        if (it.second > aa)
            return it.first;
    }
    return -1;
}
*/
