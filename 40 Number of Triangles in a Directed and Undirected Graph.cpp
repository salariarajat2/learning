#include <bits/stdc++.h>
using namespace std;
#define V 4

//Time Complexity: O(V^3), Space Complexity: O(1)

void solve(vector<vector<int>> adj)
{
    bool isDirected = false;
    int tri = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (adj[i][j] and adj[j][k] and adj[k][i])
                {
                    tri++;
                }
            }
        }
    }

    if (isDirected)
        tri /= 3;
    else
        tri /= 6;

    cout << tri << endl;
}

int main()
{
    vector<vector<int>> adj = {{0, 1, 1, 0},
                               {1, 0, 1, 1},
                               {1, 1, 0, 1},
                               {0, 1, 1, 0}};

    solve(adj);
    return 0;
}

//TIME COMPLEXITY: O(V+E)
