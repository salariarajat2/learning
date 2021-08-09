#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int t;
    cin >> t;
    while (t--)
    {

        int x;
        cin >> x;
        int cnt = 0,sum=0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= x)
            {
                sum = sum + arr[i];
                cnt++;
            }
        }
        cout << cnt << " " << sum << endl;
    }
    return 0;
}

