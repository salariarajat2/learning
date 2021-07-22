#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(v)

bool solve(int node, vector<int> &order, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    order[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (solve(it, order, vis, adj))
                return true;
        }

        else if (order[it])
            return true;
    }
    order[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0), order(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (solve(i, order, vis, adj))
                return true;
        }
    }
    return false;
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
	}

	cout << isCyclic(V, adj) << "\n";

	return 0;
}
/*
9 9
1 2
2 3
3 4
3 6
4 5
6 5
7 8
8 9
9 7
yes


9 9
1 2
2 3
3 4
3 6
4 5
6 5
7 8
7 9
8 9
no

*/

/*

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
	vis[node] = 1;
	dfsVis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (checkCycle(it, adj, vis, dfsVis))
				return true;
		}
		else if (dfsVis[it])
		{
			return true;
		}
	}
	dfsVis[node] = 0;
	return false;
}
bool isCyclic(int N, vector<int> adj[])
{
	int vis[N], dfsVis[N];
	memset(vis, 0, sizeof vis);
	memset(dfsVis, 0, sizeof dfsVis);

	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			// cout << i << endl;
			if (checkCycle(i, adj, vis, dfsVis))
			{
				return true;
			}
		}
	}
	return false;
}

*/
