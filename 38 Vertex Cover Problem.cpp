#include <bits/stdc++.h>
using namespace std;

//Time Complexity O(V + E).

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::printVertexCover()
{
    vector<bool> vis(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!vis[u])
        {
            for (auto i : adj[u])
            {
                int v = i;
                if (!vis[v])
                {
                    vis[v] = true;
                    vis[u] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (vis[i])
            cout << i << " ";
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}

/*

//for tree

// Time Complexity simple recursion it is exponential

struct node
{
    int data;
    node *left = NULL, *right = NULL;
    node(int val)
    {
        data = val;
    }
};

int vcover(node *root)
{
    if (!root)
        return 0;

    if (!root->left and !root->right)
        return 0;

    int s = 1 + vcover(root->left) + vcover(root->right);

    int a = 0;
    if (root->left)
        a += 1 + vcover(root->left->left) + vcover(root->left->right);
    if (root->right)
        a += 1 + vcover(root->right->left) + vcover(root->right->right);

    return min(s, a);
}

int main()
{
    struct node *root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);

    cout << "Size of the smallest vertex cover is " << vcover(root);

    return 0;
}

*/

