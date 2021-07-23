#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(V+E), Space Complexity: O(v)

struct Node
{
    int val;
    vector<Node *> neighbours;
    Node(int key)
    {
        val = key;
    }
};

void traverse(Node *node, Node *copy, vector<Node *> &vis)
{
    vis[copy->val] = copy;
    for (auto it : node->neighbours)
    {
        if (!vis[it->val])
        {
            Node *temp = new Node(it->val);
            (copy->neighbours).push_back(temp);
            traverse(it, temp, vis);
        }
        else
        {
            (copy->neighbours).push_back(vis[it->val]);
        }
    }
}

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;
    vector<Node *> vis(1000, NULL);
    Node *copy = new Node(node->val);
    traverse(node, copy, vis);
    return copy;
}

void bfs(Node *src)
{
    map<Node *, bool> visit;
    queue<Node *> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " << u << "\n";
        q.pop();
        for (auto i: (u->neighbours))
        {
            if (!visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

Node *buildGraph()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

int main()
{
    Node *src = buildGraph();
    cout << "dfs Traversal before cloning\n";
    bfs(src);
    Node *newsrc = cloneGraph(src);
    cout << "dfs Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}

/*
		Note : All the edges are Undirected
		Given Graph:
		1--2
		| |
		4--3
	*/
