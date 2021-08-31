#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V!), Space Complexity: O(v)

bool solve(int node, vector<int> &vis, vector<pair<int, int>> adj[], int k)
{
    vis[node] = true;
    if (k <= 0)
        return true;

    for (auto it : adj[node])
    {
        int a = it.first;
        int b = it.second;

        if (vis[a])
            continue;
        if (k <= b)
            return true;
        if (solve(a, vis, adj, k - b))
            return true;
    }
    vis[node] = false;
    return false;
}

int main()
{
    int v, e, k;
    cin >> v >> e >> k;
    vector<pair<int, int>> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<int> vis(v + 1, false);
    cout<<solve(1, vis, adj, k);
    return 0;
}

/*
10 11
23   
1 2 1
2 3 2
3 4 2 
2 5 5 
5 6 2
6 7 1
4 7 3
7 10 2
9 10 1
4 8 4
8 9 5

ans = true 
for k= 25 code returns false
*/


