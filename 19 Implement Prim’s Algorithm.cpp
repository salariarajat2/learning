#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O((v+e) logv), Space Complexity: O(v)

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

    vector<int> parent(N);
    vector<int> key(N, INT_MAX);
    vector<bool> mset(N, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();

        mset[a] = true;
        for (auto x : adj[a])
        {
            int v = x.first;
            int c = x.second;
            if (!mset[v] and c < key[v])
            {
                key[v] = c;
                parent[v] = a;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    system("cls");
    int s = accumulate(key.begin(), key.end(), 0);
    cout << s << endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " " << i << endl;
    }
}

/*
6 7 
0 1 5 
0 2 10 
0 3 100 
1 3 50 
1 4 200
3 4 250
4 5 50 



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




0 - 1
1 - 2
0 - 3
1 - 4

*/

/*
//Time Complexity: O(v^2), Space Complexity: O(v)

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<bool> mset(v, false);
    vector<int> parent(v, -1);
    vector<int> key(v, INT_MAX);
    parent[0] = -1;
    key[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int mini = INT_MAX, u;
        for (int a = 0; a < v; a++)
        {
            if (!mset[a] and key[a] < mini)
            {
                mini = key[a];
                u = a;
            }
        }
        mset[u] = true;
        for (auto x : adj[u])
        {
            int l = x.first;
            int w = x.second;
            if (!mset[l] and key[l] > w)
            {
                key[l] = w;
                parent[l] = u;
            }
        }
    }

    cout << '\n';
    int s = accumulate(key.begin(), key.end(), 0);
    cout << s << endl;

    for (int i = 1; i < v; i++)
    {
        cout << parent[i] << " " << i << endl;
    }
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
