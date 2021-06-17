#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1), low(n, -1), vis(n, 0), isArticulation(n, 0);
    int timer = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
        }
    }
    system("cls");

    for (int i = 0; i < n; i++)
    {
        if (isArticulation[i] == 1)
            cout << i << endl;
    }

    return 0;
}

/*
12 14
1 2
1 4
2 3 
3 4
4 5
5 6
6 7
6 9
7 8
8 9
8 10
10 11
10 12
11 12




4
5
6
8
10
*/
