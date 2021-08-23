#include <bits/stdc++.h>
using namespace std;

//using adjacency list, for undirected graph  ,  TC= (V+E)
int main()
{
	int v, e;
	cin >> v >> e;

	vector<int> adj[v + 1];
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u); // 	adj[u].push_back(v) or adj[v].push_back(u); or directed graph
		adj[u].push_back(v);
	}

	for (int i = 1; i <= v; i++)
	{
		cout << i << " -->  ";
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

/*
6 5
1 2
1 5
2 3
3 4
3 6
1 -->  2 5
2 -->  1 3
3 -->  2 4 6
4 -->  3
5 -->  1
6 -->  3

*/

/*
//using adjacency matrix     TC = V^2
int main()
{
	int v, e;
	cin >> v >> e;

	int adj[v + 1][v + 1];

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			adj[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for (int i = 1; i <= v; i++)
	{
		cout << i << "-->  ";
		for (int j = 1; j <= v; j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
6 5
1 2
1 5 
2 3 
3 4 
3 6


1-->  0 1 0 0 1 0
2-->  1 0 1 0 0 0
3-->  0 1 0 1 0 1
4-->  0 0 1 0 0 0
5-->  1 0 0 0 0 0
6-->  0 0 1 0 0 0

*/

/*


//for weighted graph
int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	return 0;
}

*/
