#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n], i;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans;
    int idx = lower_bound(arr, arr + n, x) - arr;
    auto idx1 = upper_bound(arr, arr + n, x) - arr - 1;

    cout << idx << " " << idx1 << endl;

    return 0;
}

/*
9 5
1 3 5 5 5 5 67 123 1
*/






/*


vector<int> find(int a[], int n, int x)
{
    int mid, low = 0, high = n - 1;
    bool flag = false;
    vector<int> ans;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            flag = true;
            break;
        }
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag == false)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    low = mid, high = mid;
    while (a[low] == x)
    {
        low--;
    }
    while (a[high] == x)
    {
        high++;
    }
    ans.push_back(low + 1);
    ans.push_back(high - 1);
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n], i;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans;
    // ans=find(arr,n,x);
    int idx = lower_bound(arr, arr + n, x) - arr;
    int idx1 = upper_bound(arr, arr + n, x) - arr - 1;
    cout << idx << " " << idx1 << endl;
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}




*/
