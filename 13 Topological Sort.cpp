#include <bits/stdc++.h>
using namespace std;

// 	Expected Time Complexity: O(V + E), Expected Auxiliary Space: O(V).

void topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            vis[x]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for (auto x : adj[a])
        {
            vis[x]--;
            if (vis[x] == 0)
                q.push(x);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topoSort(v, adj);

    return 0;
}
/*
	6 6
	1 3
	2 3
	4 0
	4 1
	5 0 
	5 2
	
	4 5 1 0 2 3 

    */
