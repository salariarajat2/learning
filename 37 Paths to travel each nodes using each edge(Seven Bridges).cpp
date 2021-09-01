#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int val)
    {
        V = val;
        adj = new list<int>[V];
    }

    Graph addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printEulerTour();
    void printEulerUtil(int s);
    bool isValidNextEdge(int a, int b);
    int dfs(int u, bool *vis);
    void rmvEdge(int u, int v);
};

void Graph::rmvEdge(int u, int v)
{
    list<int>::iterator a = find(adj[u].begin(), adj[u].end(), v);
    *a = -1;

    auto b = find(adj[v].begin(), adj[v].end(), u);
    *b = -1;
}

int Graph::dfs(int u, bool *vis)
{
    vis[u] = true;
    int count = 1;

    for (auto i : adj[u])
        if (i != -1 && !vis[i])
            count += dfs(i, vis);
    return count;
}

bool Graph::isValidNextEdge(int u, int v)
{
    int c = 0;

    for (auto i : adj[u])
    {
        if (i != -1)
        {
            c++;
        }
    }
    if (c == 1)
    {
        return true;
    }

    bool visited[V];
    memset(visited, false, V);
    int count1 = dfs(u, visited);

    rmvEdge(u, v);

    memset(visited, false, V);
    int count2 = dfs(u, visited);

    addEdge(u, v);

    return (count1 > count2) ? false : true;
}

void Graph::printEulerUtil(int u)
{
    for (auto i : adj[u])
    {
        int v = i;
        if (v != -1 and isValidNextEdge(u, v))
        {
            cout << u << "-" << v << " ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}

void Graph::printEulerTour()
{
    int u = 0;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() & 1)
        {
            u = i;
            break;
        }
    }
    printEulerUtil(u);
    cout << endl;
}

int main()
{
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printEulerTour();

    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 0);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);
    g3.printEulerTour();

    return 0;
}

