#include <bits/stdc++.h>
using namespace std;

bool solve(int *arr, int n, int mid, int m)
{
    int sum = 0, stu = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (sum + arr[i] > mid)
        {
            stu++;
            sum = arr[i];
            if (stu > m)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m)
{
    int lb = 0, s = 0, ub;
    for (int i = 0; i < n; i++)
        s += arr[i];
    ub = s;
    int ans = 0;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (solve(arr, n, mid, m))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int m;
    cin >> m;
    cout << findPages(A, n, m) << endl;

    return 0;
}
/*
4
12 34 67 90 
2

ans= 113
*/

