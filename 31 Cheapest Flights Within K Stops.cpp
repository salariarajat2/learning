#include <bits/stdc++.h>
using namespace std;

//Bellman Ford Algorithm
//Time complexity: O(kE)

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    int size = flights.size();
    if (!size)
        return -1;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < K + 1; i++)
    {
        vector<int> temp(dist);
        for (auto f : flights)
        {
            if (dist[f[0]] == INT_MAX)
                continue;
            temp[f[1]] = min(temp[f[1]], dist[f[0]] + f[2]);
        }
        swap(temp, dist);
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main()
{
    int e = 3;
    vector<vector<int>> a = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int scr = 0, dst = 2, k = 1;
    cout << findCheapestPrice(e, a, scr, dst, k);

    // ans = 200;
}

/*
//Using Dijkstra’s Algorithm
//Time complexity: O(ElogV)

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    vector<vector<pair<int, int>>> graph(n);

    for (auto v : flights)
        graph[v[0]].push_back({v[1], v[2]});

    pq.push({0, src, K + 1});

    while (!pq.empty())
    {
        auto [cost, node, stops] = pq.top();
        pq.pop();
        if (node == dst)
            return cost;
        if (stops == 0)
            continue;
        for (auto p : graph[node])
        {
            auto [to_node, weight] = p;
            pq.push({cost + weight, to_node, stops - 1});
        }
    }

    return -1;
}
*/
