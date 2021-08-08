#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n^2), Space Complexity: O(1)

int aa(int *arr, int n, int sum)
{
    sort(arr, arr + n);
    long long cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l <= r)
        {
            if (arr[i] + arr[l] + arr[r] < sum)
            {
                cnt += (r - l);
                l++;
            }
            else
                r--;
        }
    }
    return cnt;
}

int main()
{
    int n;
    int x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << aa(arr, n, x);
}
