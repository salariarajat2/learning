#include <bits/stdc++.h>
using namespace std;

void aa(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int l = 0, r = n - 1;
    for (int i = 0; i <= r; i++)
    {
        if (arr[i] < a)
        {
            swap(arr[i], arr[l]);
            l++;
        }
        else if (arr[i] > b)
        {
            swap(arr[i], arr[r]);
            r--;
            i--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    aa(arr, a, b);

    return 0;
}
/*
5 3 4
6 3 2 1 5
*/
