#include <bits/stdc++.h>
using namespace std;

// 	Expected Time Complexity: O(V + E), Expected Auxiliary Space: O(V).

int main()
{
    int v, e;
    cin >> v>>e;
    vector<int> adj[v+1];
    vector<int> in(v+1, 0);
    vector<int> ans(v+1,0);
    queue<int> q;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= v; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto c : adj[a])
        {
            in[c]--;
            if (in[c] == 0)
            {
                ans[c] = ans[a] + 1;
                q.push(c);
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        cout << ans[i] << " ";
    }
}


    // 1 3
    // 1 4
    // 1 5
    // 2 3
    // 2 8
    // 2 9
    // 3 6
    // 4 6
    // 4 8
    // 5 8
    // 6 7
    // 7 8
    // 8 10

    // ans = 1 1 2 2 2 3 4 5 2 6
