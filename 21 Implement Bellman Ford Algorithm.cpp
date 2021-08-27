#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(VE), Space Complexity: O(v)

struct node
{
    int v, u, wt;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

int main()
{
    int l, m;
    cin >> l >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    int src;
    cin >> src;
    vector<int> dis(l, INT_MAX);
    dis[src] = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (auto it : edges)
        {
            if (dis[it.u] + it.wt < dis[it.v])
            {
                dis[it.v] = dis[it.u] + it.wt;
            }
        }
    }

    bool f = true;
    for (auto it : edges)
    {
        if (dis[it.u] + it.wt < dis[it.v])
        {
            f = false;
            cout << "-ve edge cycle";
            break;
        }
    }

    if (f)
        for (int i = 0; i <= l; i++)
        {
            cout << i << " " << dis[i] << endl;
        }
}

/* 
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0


ans- 

0 0
1 -1
2 2
3 -2
4 1


*/

/*
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int a = edges[j][0];
            int b = edges[j][1];
            int w = edges[j][2];

            if (dist[a] != INT_MAX && dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            } 
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];

        if (dist[a] != INT_MAX && dist[a] + w < dist[b])
        {
            return 1;
        }
    }
    return 0;
}
*/
