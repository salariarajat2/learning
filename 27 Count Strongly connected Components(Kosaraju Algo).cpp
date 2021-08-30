#include <bits/stdc++.h>
using namespace std;

// TC = O(V+E)  , SC = O(V+E)

vector<int> order;
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
    order.push_back(node);
}
void rdfs(int node, vector<int> &vis1, vector<int> a[])
{
    vis1[node] = 1;
    cout << node << " "; //print the component elements
    for (auto it : a[node])
    {
        if (!vis1[it])
        {
            rdfs(it, vis1, a);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    order.clear();
    vector<int> a[V];
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            a[it].push_back(i); //making reverse graph
        }
    }
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj);
        }
    }
    int count = 0;
    vector<int> vis1(V, 0);
    for (int i = V - 1; i >= 0; i--)
    {
        if (!vis1[order[i]])
        {
            rdfs(order[i], vis1, a);
            count++;
            cout << endl;
        }
    }
    return count;
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
    }
    cout << kosaraju(V, adj); //print total count of strongly connected graph
}

/*
Using stack

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, transpose);
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
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i); //making reverse graph
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}

/*
5 5
0 1
1 2
2 0
1 3
3 4

ans- 

SCC: 0 2 1
SCC: 3
SCC: 4 
*/

