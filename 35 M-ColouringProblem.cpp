#include <bits/stdc++.h>
using namespace std;
#define c 4

// Time Complexity: O(M^N), Auxiliary Space: O(N).

bool can_color_with_i(bool graph[c][c], int x, int y, vector<int> &colr)
{
    for (int i = 0; i < colr.size(); i++)
    {
        if (graph[x][i] && colr[i] == y)
        {
            return false;
        }
    }
    colr.push_back(y);
    return true;
}

bool find_coloring(bool graph[c][c], int m, int V, int node, vector<int> &colr)
{
    if (node == V)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (can_color_with_i(graph, node, i, colr) && find_coloring(graph, m, V, node + 1, colr))
        {
            return true;
        }
    }
    colr.pop_back();//backtracking
    return false;
}

bool graphColoring(bool graph[c][c], int m, int V)
{
    vector<int> colr;
    if (find_coloring(graph, m, V, 0, colr))
    {
        for (int i = 0; i < V; i++)
        {
            cout << colr[i] << " ";
        }
        cout << endl;
        return true;
    }
    return false;
}

int main()
{
    bool graph[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    // Number of colors
    int m = 3;
    cout << graphColoring(graph, m, 4) << endl;

    return 0;
}

/*
Time Complexity: O(V + E).
Space Complexity: O(V). For Storing Visited List.

class node
{
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node> &nodes, int n, int m)
{

    // Create a visited array of n
    // nodes, initialized to zero
    vector<int> visited(n + 1, 0);

    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;

    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++)
    {

        if (visited[sv])
            continue;

        // If the starting point is unvisited,
        // mark it visited and push it in queue
        visited[sv] = 1;
        queue<int> q;
        q.push(sv);

        // BFS Travel starts here
        while (!q.empty())
        {

            int top = q.front();
            q.pop();

            // Checking all adjacent nodes
            // to "top" edge in our queue
            for (auto it = nodes[top].edges.begin();
                 it != nodes[top].edges.end(); it++)
            {

                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;

                // If number of colors used shoots m, return
                // 0
                maxColors = max(maxColors, max(nodes[top].color,
                                               nodes[*it].color));
                if (maxColors > m)
                    return 0;

                // If the adjacent node is not visited,
                // mark it visited and push it in queue
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }

    return 1;
}

int main()
{

    int n = 4;
    bool graph[n][n] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3; // Number of colors
    vector<node> nodes(n + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

    cout << canPaint(nodes, n, m);
    cout << "\n";

    return 0;
}
*/
