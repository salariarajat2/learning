#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2), Auxiliary Space: O(N2).

int mat[22][22];
int visited[22][22];

bool safe(int n, int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

void knight(int n, int xi, int yi)
{
    int row[] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int col[] = {-1, 1, -2, 2, -1, 1, -2, 2};
    int k;
    queue<pair<int, int>> q;
    q.push(make_pair(xi, yi));
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        visited[x.first][x.second] = 1;
        for (k = 0; k < 8; k++)
        {
            if (safe(n, x.first + row[k], x.second + col[k]) && visited[x.first + row[k]][x.second + col[k]] == 0)
            {
                mat[x.first + row[k]][x.second + col[k]] = mat[x.first][x.second] + 1;
                q.push(make_pair(x.first + row[k], x.second + col[k]));
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, xi, yi, xf, yf, i, j;
        cin >> n >> xi >> yi >> xf >> yf;
        memset(mat, 0, sizeof(mat));
        memset(visited, 0, sizeof(visited));
        knight(n, xi - 1, yi - 1);
        cout << mat[xf - 1][yf - 1] << endl;
    }
    return 0;
}

/*
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}

ans = 3;
*/
