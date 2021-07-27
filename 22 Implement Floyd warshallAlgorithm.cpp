#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999

// Time Complexity: O(V^3)

void print(int d[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "INF"
                     << "  ";
            }
            else
            {
                cout << d[i][j] << "    ";
            }
        }
        cout << endl;
    }
}

void floydWarshall(int adj[][V])
{
    int d[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            d[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j] and (d[i][k] != INF and d[k][j] != INF))
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int f = 0;
    for (int i = 0; i < V; i++)
    {
        if (d[i][i] < 0)
        {
            f = 1;
            cout << "-ve edge cycel";
            break;
        }
    }

    if (!f)
    {
        print(d);
    }
}

int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);
    return 0;
}

/*
		
	int graph[V][V] = { {0 , 1 , INF , INF},
						{INF , 0 , -1 , INF},
						{INF , INF , 0 , -1},
						{-1 , INF , INF , 0}};

ans  = "Yes";

}

*/