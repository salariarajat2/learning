#include <bits/stdc++.h>
using namespace std;

// TC = O(n^2) , SC= O(n^2)

int dp[1001][1001];

long long func(int *arr, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int a = arr[i] + min(func(arr, i + 2, j), func(arr, i + 1, j - 1)); //we are taking element form left side
    int b = arr[j] + min(func(arr, i + 1, j - 1), func(arr, i, j - 2)); //we are taking element form right side

    return max(a, b);
}

long long maximumAmount(int arr[], int n)
{
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    return func(arr, 0, n - 1);
}

int main()
{
    int N = 4, A[] = {5, 3, 7, 10};
    cout << maximumAmount(A, N);
    // Output: 15
}
