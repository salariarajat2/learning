#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

int kadane(int *arr, int n)
{

    int max_global, max_current;
    max_global = INT_MIN;
    max_current = 0;
    //max_current=0,max_global=INT_MIN;

    for (int i = 0; i < n; i++)
    {

        max_current = max(arr[i], max_current + arr[i]);
        if (max_current < 0)
            max_current = 0;

        if (max_current > max_global)
        {
            max_global = max_current;
        }
    }
    return max_global;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << kadane(arr, n) << "\n";
    }
    return 0;
}
/*
5
5
1 2 3 -2 5

-2 -3 4 -1 -2 1 5 -3
*/

/*
//for negative elements

int kadane(int *arr, int n)
{

    int max_global, max_current;
    max_global = max_current = arr[0];

    for (int i = 0; i < n; i++)
    {

        max_current = max(arr[i], max_current + arr[i]);
        max_global = max(max_global, max_current);
    }
    return max_global;
}
*/
