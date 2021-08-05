#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)


int main()
{
    int i, n, ma = INT_MIN, mi = INT_MAX;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mi = (mi < a[i]) ? mi : a[i];
        ma = (ma > a[i]) ? ma : a[i];
    }
    cout << mi<< " " << ma << endl;

    return 0;
}
