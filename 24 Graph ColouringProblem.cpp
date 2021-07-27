#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(1<<V), Space Complexity: O(V)

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> res(v, -1);
    vector<bool> avail(v, false);
    res[0] = 0;
    int ans = 0;
    for (int i = 1; i < v; i++)
    {
        for (auto x : graph[i])
        {
            if (res[x] != -1)
            {
                avail[res[x]] = true;
            }
        }

        int cr;
        for (cr = 0; cr < v; cr++)
        {
            if (avail[cr] == false)
            {
                break;
            }
        }

        res[i] = cr;
        ans = max(ans, cr + 1);
        for (auto x : graph[i])
        {
            if (res[x] != -1)
            {
                avail[res[x]] = false;
            }
        }
    }
    system("cls");
    cout << ans << endl;
    for (int i = 0; i < v; i++)
    {
        cout << res[i] << " ";
    }
}

/*
5 6
0 1
1 3
2 3
0 2
2 4
1 4

ans = 2
      0 1 1 0 0

5 7
0 1
1 3
2 3
0 2
2 4
1 4
0 4

ans = 3
0 1 1 0 2
*/
