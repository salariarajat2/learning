#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(e logv), Space Complexity: O(v)

struct node
{
    int u, v, wt;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findpar(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = findpar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &size)
{
    u = findpar(u, parent);
    v = findpar(v, parent);

    if (size[u] > size[v])
    {
        parent[v] = u;
        size[v] += size[u];
    }
    else
    {
        parent[u] = v;
        size[u] += size[v];
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<node> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    vector<int> size(v, 0);
    int cost = 0;
    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findpar(it.u, parent) != findpar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back(make_pair(it.u, it.v));
            unionn(it.u, it.v, parent, size);
        }
    }

    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}

/*
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7

ans = 
16
0 1
1 2
1 4
0 3
*/
