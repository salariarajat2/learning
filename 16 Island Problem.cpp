#include <bits/stdc++.h>
using namespace std;

//Expected Time Compelxity: O(n*m), Expected Space Compelxity: O(1)

void remove(vector<vector<int>> &A, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (A[i][j] == 0)
        return;
    A[i][j] = 0;
    remove(A, i - 1, j - 1, n, m );
    remove(A, i - 1, j, n, m );
    remove(A, i - 1, j + 1, n, m );
    remove(A, i, j - 1, n, m );
    remove(A, i, j + 1, n, m );
    remove(A, i + 1, j - 1, n, m );
    remove(A, i + 1, j, n, m );
    remove(A, i + 1, j + 1, n, m );
}
int findIslands(vector<vector<int>> &A, int n, int m)
{
    if (n == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                count++;
                remove(A, i, j, n, m);
            }
        }
    }
    return count;
}

// Driver Code
int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << findIslands(M, M.size(), M[0].size());
    return 0;
}

//ans = 5
