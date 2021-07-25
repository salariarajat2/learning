#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(E log v), Space Complexity: O(v)

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    int src;
    cin >> src;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v + 1, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int b = pq.top().first;
        int c = pq.top().second;
        pq.pop();
        for (auto it : adj[c])
        {
            int d = it.first;
            int e = it.second;
            if (dist[d] > dist[c] + e)
            {
                dist[d] = dist[c] + e;
                pq.push(make_pair(dist[d], e));
            }
        }
    }
    system("cls");
    for (int i = 1; i <= v; i++)
    {
        cout << dist[i] << " ";
    }
}

/*
5 12
1 2 2
1 4 1
2 1 2
2 3 4
2 5 5
3 2 4
3 4 3
3 5 1
4 1 1
4 3 3
5 2 5
5 3 1
1

ans-  0 2 4 1 5
*/

/*

void printSolution(vector<int> dist)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "    " << dist[i] << endl;
    }
}

void dijkstra(int graph[][V], int src)
{
    vector<int> d(V, INT_MAX);
    vector<bool> s(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        s[b] = true;
        for (int i = 0; i < V; i++)
        {
            if (!s[i] and graph[b][i] and d[i] > graph[b][i] + d[b])
            {
                d[i] = graph[b][i] + d[b];
                pq.push(make_pair(d[i], i));
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << i << "  " << d[i] << endl;
    }
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}



*/

//Time Complexity: O(v^2), Space Complexity: O(v*v)
/*
#define V 9

int minDistance(vector<int> dist, vector<bool> sptSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(vector<int> dist)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "    " << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
*/
