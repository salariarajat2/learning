#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(V+E)

void dfs(int i, vector<int> g[], vector<int> &vis)
{
    vis[i] = 1;
    for (auto it : g[i])
    {
        if (!vis[it])
        {
            dfs(it, g, vis);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> g[n];
    int m = connections.size();
    if (m < n - 1)
        return -1;
    for (int i = 0; i < m; i++)
    {
        g[connections[i][0]].push_back(connections[i][1]);
        g[connections[i][1]].push_back(connections[i][0]);
    }
    vector<int> vis(n, 0);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            c++;
            dfs(i, g, vis);
        }
    }
    return c - 1;
}
int main()
{
    int v=6, e=5;
    vector<vector<int>> adj =  {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout << makeConnected(v, adj);
}

// ans = 2
