#include <bits/stdc++.h>
using namespace std;

//Time complexity: O(V+E) , Space complexity: O(V)

int timer = 1;
vector<int> in;
vector<int> out;
void resize(int n)
{
    in.resize(n+1);
    out.resize(n+1);
}
void dfs(int src, int par, vector<int> adj[])
{
    in[src] = timer++;
    for (auto it : adj[src])
    {
        if (it != par)
        {
            dfs(it, src, adj);
        }
    }
    out[src] = timer++;
}

bool check(int x, int y)
{
    if (in[x] > in[y] and out[x] < out[y])
        return true;
    return false;
}

int main()
{
    int e;
    cin >> e;
    timer = 1;
    resize(e);
    vector<int> adj[e+1];
    for (int i = 0; i < e - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int dire, x, y;
        cin >> dire >> x >> y;

        if (!check(x, y) and !check(y, x))
        {
            cout << "NO" << endl;
            continue;
        }

        if (dire == 0)
        {
            if (check(y, x))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        if (dire == 1)
        {
            if (check(x, y))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

/*
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1



ans =
YES
NO
NO
NO
YES

*/

