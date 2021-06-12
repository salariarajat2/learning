#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n)
{
    long long totalsum = arr[0];
    long long maxval = arr[0], minval = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(minval, maxval);//point of swap define below

        maxval = max<long long int>(arr[i], maxval * arr[i]);
        minval = min<long long int>(arr[i], minval * arr[i]);

        totalsum = max(maxval, totalsum);
    }
    return totalsum;
}




int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        auto ans = maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

/*
6
2 3 4 5 -1 0
 
ans 120


5
5
6 -3 -10 0 2
maxval-3
minval-18
totalsum6
maxval180
minval-10
totalsum180
maxval0
minval0
totalsum180
maxval2
minval0
totalsum180
180
*/

