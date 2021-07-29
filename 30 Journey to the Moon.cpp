#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(v)


void dfs(int node, vector<int> &vis, vector<int> adj[], int &counter)
{
    vis[node] = 1;
    counter++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, counter);
        }
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
        adj[v].push_back(u);
    }

    vector<int> vis(v, 0);
    vector<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            int counter = 0;
            dfs(i, vis, adj, counter);
            s.push_back(counter);
        }
    }

    int val = (v * (v - 1)) / 2;
    for (int i = 0; i < s.size(); i++)
    {
        int a = (s[i] * (s[i] - 1)) / 2;
        val = val - a;
    }
    cout << val;
}


/*

5 3
0 1
2 3
0 4

ans = 6
*/

/*
    long long res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s[i] * (v - s[i]);
    res /= 2;

    cout << res;
    */
