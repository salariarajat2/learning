#include <bits/stdc++.h>
using namespace std;
vector<int> order;

//Time Complexity: O(V+E), Space Complexity: O(v)

void topo(int node, vector<int> &vis, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            topo(it.first, vis, adj);
        }
    }
    order.push_back(node);
}

int main()
{
    int v, e;
    cin >> v >> e;
    int s;
    cin >> s;
    vector<pair<int, int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            topo(i, vis, adj);
        }
    }

    vector<int> d(v, INT_MIN);
    d[s] = 0;
    for (int i = v - 1; i >= 0; i--)
    {
        if (d[order[i]] != INT_MIN)
        {
            for (auto it : adj[order[i]])
            {
                int v = d[it.first];
                int w = it.second;
                int u = d[order[i]];
                if (u + w > v)
                {
                    d[it.first] = u + w;
                }
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (i != s and d[i] != INT_MIN)
        {
            cout << s << " -> " <<i
                 << " = " << d[i] << endl;
        }
    }
}

/*
6 7
1
0 1 5
1 5 5
5 3 2
3 2 20
4 2 10
5 2 50
1 4 2

ans=
1 -> 2 = 55
1 -> 3 = 7
1 -> 4 = 2
1 -> 5 = 5

*/


