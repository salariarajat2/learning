#include <bits/stdc++.h>
using namespace std;

//TC = O(n) , SC= O(1)

int func(int *arr, int n, int x)
{
    int i = 0, j = 0, s = 0, mi = INT_MAX;
    while (i <= j and j < n)
    {
        while (j < n and s <= x)
        {
            s += arr[j++];
        }
        while (i <= j and s > x)
        {
            mi = min(mi, j - i);
            s -= arr[i++];
        }
    }
    return mi;
}

int main()
{

    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << func(arr, n, x);
}

/*

5
6
51
1 4 45 6 0 19
ans 3
*/

/*
//TC- O(n^2)  . SC=O(1)

int main()
{
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
          cin>>arr[i];
        }

        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum=0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum > x)
                {
                    diff = min(diff, j-i + 1);
                }
            }
        }

        cout << diff;
    
    return 0;
}

*/
