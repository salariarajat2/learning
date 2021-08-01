#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(v^2), Space Complexity: O(v)

int f = 0;
void bipar(int src, int par, int cl, vector<int> rev[], vector<int> &clr)
{
    clr[src] = cl;

    for (auto it : rev[src])
    {
        if (!clr[it])
        {
            bipar(it, src, 3 - cl, rev, clr);
        }
        else if (it != par and cl == clr[it])
        {
            f = 1;
            break;
        }
    }
}

void reverse_graph(vector<int> adj[], int V)
{
    vector<int> dummy(V, false);
    vector<int> rev[V];
    for (int i = 0; i < V; i++)
    {
        dummy[i] = true;
        for (auto it : adj[i])
        {
            dummy[it] = true;
        }

        for (int j = 0; j < V; j++)
        {
            if (dummy[j] == false)
            {
                rev[i].push_back(j);
                rev[j].push_back(i);
            }
        }
        dummy.clear();
    }

    vector<int> clr(V, 0);
    bipar(0, 0, 1, rev, clr);
    if (!f)
    {
        cout << "Two clique";
    }
    else
    {
        cout << "not possible";
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    reverse_graph(adj, V);
}

/*
5 5
0 1
1 2
2 0
0 3
3 4

ans= Two clique
*/
