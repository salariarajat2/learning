#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m), Auxiliary Space: O(1)

int func(int n, int m, int **arr)
{
    for (int col = m - 2; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            int right = arr[row][col + 1];
            int right_up = (row == 0) ? 0 : arr[row - 1][col + 1];
            int right_down = (row == m - 1) ? 0 : arr[row + 1][col + 1];

            arr[row][col] += max(right, max(right_down, right_up));
        }
    }

    int ans = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, arr[i][0]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << func(n, m, arr);
}

/*
4 4
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2

ans = 16
*/
