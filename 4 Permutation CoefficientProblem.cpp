#include <bits/stdc++.h>
using namespace std;

// TC = O(n), SC = O(1)

void func(int n, int k)
{
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= (n - i);
    }
    cout << ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    func(n, k);
}

/*

//Permudation Cofficient
// TC = O(n), SC = O(n)

void func(int n, int k)
{
    int *arr = new int[n + 1];
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i * arr[i - 1];
    }
    cout << arr[n] / arr[n - k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    func(n, k);
}
*/
