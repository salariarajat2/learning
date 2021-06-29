#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(h)

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int solve(Node *root, int n)
{
    if (!root)
        return 0;
    if (root->data == n)
        return 1;
    int j = solve(root->left, n);
    int k = solve(root->right, n);

    if (!j and !k)
        return 0;

    return j + k + 1;
}

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 or root->data == n2)
        return root;

    Node *l = LCA(root->left, n1, n2);
    Node *r = LCA(root->right, n1, n2);
    if (l and r)
        return root;

    if (l)
        return l;
    else
        return r;
}

int findDist(Node *root, int a, int b)
{
    Node *l = LCA(root, a, b);
    int i = solve(l, a);
    int m = solve(l, b);
    return (i + m - 2);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    int a = 2, b = 3;
    cout << findDist(root, a, b);
}





/*
int findLevel(Node *root, int k, int level)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return level;

    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}

Node *findDistUtil(Node *root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1)
    {
        d1 = lvl;
        return root;
    }
    if (root->data == n2)
    {
        d2 = lvl;
        return root;
    }

    Node *left_lca = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl + 1);
    Node *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl + 1);

    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2 * lvl;
        return root;
    }

    return (left_lca) ? left_lca : right_lca;
}

int findDistance(Node *root, int n1, int n2)
{
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);

    if (d1 != -1 && d2 != -1)
        return dist;

    if (d1 != -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }

    if (d2 != -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }

    return -1;
}
*/
