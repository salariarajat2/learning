#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &size)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (size[u] < size[v])
    {
        parent[u] = v;
        size[v] += size[u];
    }
    else
    {
        parent[v] = u;
        size[u] += size[v];
    }
}


int main()
{
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> size(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back(make_pair(it.u, it.v));//mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, size);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
    return 0;
}
/*
5 12
0 1 2
0 3 6
1 0 2
1 2 3
1 3 8
1 4 5
2 1 3
2 4 7
3 0 6
3 1 8
4 1 5
4 2 7




16
0 - 1
1 - 2
1 - 4
0 - 3
*/
