#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(v)

int f;
void dfs(int node, int parent, int clr, vector<int> adj[], vector<int> &vis)
{
    vis[node] = clr;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, node, 3 - clr, adj, vis);
        }
        else if (it != parent and clr == vis[it])
        {
            f = 1;
            break;
        }
    }
}

int main()
{
    int V, e;
    cin >> V >> e;
    vector<int> adj[V];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    f = 0;
    vector<int> vis(V, 0);
    dfs(0, 0, 1, adj, vis);
    if (!f)
    {
        cout << "bipartatie";
    }
    else
    {
        cout << "not bipartite";
    }
}

/*
8 8
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/

