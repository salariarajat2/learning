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

int solve(Node *root)
{
    if (!root)
        return 0;

    int x = solve(root->left);
    int y = solve(root->right);

    int a = root->data;
    root->data = x + y;
    return x + y + a;
}
void toSumTree(Node *node)
{
    solve(node);
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *head = new Node(10);
    head->left = new Node(-2);
    head->right = new Node(6);
    head->left->left = new Node(8);
    head->left->right = new Node(-4);
    head->right->left = new Node(7);
    head->right->right = new Node(5);

    toSumTree(head);
    inorder(head);
}

/*
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

ans= 0 4 0 20 0 12 0 

*/
