#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Auxiliary Space: O(1)

int mod = 1e9 + 7;
int func(int n, int k)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    long long same = k % mod;
    long long diff = (k * (k - 1)) % mod;
    for (int i = 3; i <= n; i++)
    {
        long long prev = diff % mod;
        diff = ((same + diff) * (k - 1)) % mod;
        same = prev % mod;
    }
    return (same + diff) % mod;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << func(n, k);
}

/*
N=2,  K=4

ans = 16
*/
