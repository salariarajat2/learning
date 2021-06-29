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

Node *kthAncestor(Node *root, int node, int &k)
{
    if (!root)
        return NULL;

    if (root->data == node or kthAncestor(root->left, node, k) or kthAncestor(root->right, node, k))
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            cout << root->data << " ";
            return NULL;
        }
        return root;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2, node = 5;
    kthAncestor(root, node, k);

    return 0;
}

