#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> make_graph(int v, vector<pair<int, int>> &adj)
{
    vector<unordered_set<int>> graph(v);
    for (auto pre : adj)
        graph[pre.second].insert(pre.first);
    return graph;
}

bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}

bool canFinish(int v, vector<pair<int, int>> &adj)
{
    vector<unordered_set<int>> graph = make_graph(v, adj);
    vector<bool> onpath(v, false), visited(v, false);
    for (int i = 0; i < v; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}

int main()
{
    int v = 4;

    vector<pair<int, int>> adj;

    // for adj: [[1, 0], [2, 1], [3, 2]]

    adj.push_back(make_pair(1, 0));
    adj.push_back(make_pair(2, 1));
    adj.push_back(make_pair(3, 2));
    if (canFinish(v, adj))
    {
        cout << "Possible to finish all tasks";
    }
    else
    {
        cout << "Impossible to finish all tasks";
    }

    return 0;
}



/*

vector<unordered_set<int>> make_graph(int numTasks,vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

vector<int> compute_indegree(vector<unordered_set<int>> &graph)
{
    vector<int> degrees(graph.size(), 0);
    for (auto i : graph)
        for (int neigh : i)
            degrees[neigh]++;
    return degrees;
}

bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
    vector<int> degrees = compute_indegree(graph);
    for (int i = 0; i < numTasks; i++)
    {
        int j = 0;
        for (; j < numTasks; j++)
            if (!degrees[j])
                break;
        if (j == numTasks)
            return false;
        degrees[j] = -1;
        for (int neigh : graph[j])
            degrees[neigh]--;
    }
    return true;
}
*/
