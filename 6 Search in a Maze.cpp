#include <bits/stdc++.h>
#define MAX 4
using namespace std;

// TC= O((N^2)^4) , SC= O(L * X), L = length of the path, X = number of paths.

vector<string> v;
void dfs(int i, int j, string s, int m[][MAX], int n, vector<vector<int>> &vis)
{
    if (i < 0 or j < 0 or i >= n or j >= n)
        return;
    if (vis[i][j] or !m[i][j])
        return;
    if (i == n - 1 and j == n - 1)
    {
        v.push_back(s);
        return;
    }
    vis[i][j] = 1;
    dfs(i - 1, j, s + 'U', m, n, vis);
    dfs(i + 1, j, s + 'D', m, n, vis);
    dfs(i, j - 1, s + 'L', m, n, vis);
    dfs(i, j + 1, s + 'R', m, n, vis);

    vis[i][j] = 0;//backtracking
}


vector<string> findPath(int m[][MAX], int n)
{
    v.clear();
    if (m[0][0] == 0)
        return v;
    if (m[n - 1][n - 1] == 0)
        return v;
    string s = "";
    vector<vector<int>> vis(n, vector<int>(n));
    dfs(0, 0, s, m, n, vis);
    sort(v.begin(), v.end());
    return v;
}


int main()
{
    int m[MAX][MAX] = {{1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}};

    int n = sizeof(m) / sizeof(m[0]);
    vector<string> sa = findPath(m, n);
    for (int i = 0; i < sa.size(); i++)
    {
        cout << sa[i] << " ";
    }

    return 0;
}

/*
ans = DDRDRR DRDDRR 
*/

/*
bool isSafe(int row, int col, int m[][MAX], int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
        col == n || visited[row][col] || m[row][col] == 0)
        return false;

    return true;
}

void printPathUtil(int row, int col, int m[][MAX], int n, string &path, vector<string> &possiblePaths, bool visited[][MAX])
{

    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1)
    {
        possiblePaths.push_back(path);
        return;
    }
    visited[row][col] = true;

    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,path, possiblePaths, visited);
        path.pop_back();
    }

    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,path, possiblePaths, visited);
        path.pop_back();
    }

    visited[row][col] = false;
}

void printPath(int m[MAX][MAX], int n)
{
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));

    printPathUtil(0, 0, m, n, path, possiblePaths, visited);

    for (int i = 0; i < possiblePaths.size(); i++)
        cout << possiblePaths[i] << " ";
}
*/
