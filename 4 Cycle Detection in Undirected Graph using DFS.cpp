#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(v)

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (checkForCycle(it, node, vis, adj))
				return true;
		}
		else if (it != parent)
			return true;
	}

	return false;
}

bool isCycle(int V, vector<int> adj[])
{
	vector<int> vis(V, 0);
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			if (checkForCycle(i, -1, vis, adj))
				return true;
		}
	}

	return false;
}

// { Driver Code Starts.
int main()
{
	int tc;

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

	bool ans = isCycle(V, adj);
	if (ans)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}

/*

8 6
1 3
3 4
2 3
5 6
6 7
7 8


8 7
1 3
3 4
2 3
5 6
5 8
6 7
7 8
*/
