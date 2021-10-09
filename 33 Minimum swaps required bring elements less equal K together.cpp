#include <bits/stdc++.h>
using namespace std;

//TC = O(n), sc= O(1)

int answer(int arr[], int n, int k)
{
    int good = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++good;

    int bad = 0;
    for (int i = 0; i < good; ++i)
        if (arr[i] > k)
            ++bad;

    int ans = bad;
    for (int i = 0, j = good; j < n; ++i, ++j)
    {
        if (arr[i] > k)
            --bad;

        if (arr[j] > k)
            ++bad;

        ans = min(ans, bad);
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;
    int i, arr[size], k;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << answer(arr, size, k);
}
/*
5 3
2 1 5 6 3
*/

/*
int minSwap(int *arr, int n, int k) {
    
    int g=0,b=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k) g++;
    }
    for (int i = 0; i < g; i++)
    {
        if (arr[i] > k) b++;
    }

    int mi = 1e5;
    int i = 0;
    int j = g - 1;
    while (j < n)
    {
        mi = min(mi, b);
        j++;
        if (j < n and arr[j] > k) b++;
        if (arr[i] > k) b--;
        
        i++;
    }
return mi;
    
}
*/
