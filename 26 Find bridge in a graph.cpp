#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E)

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                cout << node << " " << it << endl;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1); //time of insertion
    vector<int> low(n, -1); //lowest time of insertion
    vector<int> vis(n, 0);
    int timer = 0;
    system("cls");
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
    }

    return 0;
}
/*
13 14
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

ans=
8 10
5 6
4 5 


4 3
0 1
1 2
2 3

ans
2 3
1 2
0 1
*/
