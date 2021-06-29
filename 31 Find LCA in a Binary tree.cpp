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

Node *findLCAUtil(struct Node *root, int n1, int n2, bool &v1, bool &v2)
{

    if (root == NULL)
        return NULL;

    if (root->data == n1)
    {
        v1 = true;
        return root;
    }
    if (root->data == n2)
    {
        v2 = true;
        return root;
    }

    Node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

bool find(Node *root, int k)
{
    if (root == NULL)
        return false;

    if (root->data == k || find(root->left, k) || find(root->right, k))
        return true;

    return false;
}

Node *findLCA(Node *root, int n1, int n2)
{
    bool v1 = false, v2 = false;
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;

    return NULL;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *lca = findLCA(root, 4, 5);
    if (lca != NULL)
        cout << "LCA(4, 5) = " << lca->data;
    else
        cout << "datas are not present ";
}


/*
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

*/

/*

// Time Complexity: O(N), Auxiliary Space: O(h)

bool findPath(Node *root, vector<int> &path, int k)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == k)
        return true;

    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;

    path.pop_back();
    return false;
}

int findLCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

*/
