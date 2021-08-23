#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(V)

vector<int> ans;
void solve(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            solve(it, vis, adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    ans.clear();
    vector<int> vis(V, 0);
    solve(0, vis, adj);
    return ans;
}

int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = dfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
4 4
0 1
0 2
0 4
4 3

ans= 0 1 2 4 3

*/
