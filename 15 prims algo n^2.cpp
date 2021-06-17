#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    vector<int> parent(N, -1);

    vector<int> key(N, INT_MAX);

    vector<bool> mstSet(N, false);

    //    for (int i = 0; i < N; i++)
    //        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; count++)
    {

        int mini = INT_MAX, u;

        for (int v = 0; v < N; v++)
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }
    cout << endl;

    for (int i = 1; i < N; i++)
    {

        cout << parent[i] << " - " << i << " \n";
    }

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


ans 0-1  1-2  0-3  1-4

*/
