#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(h)    //Inorder Traversal (Left Root Right)

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int f;
int solve(Node *root)
{
    if (!root)
        return 0;
    int x = solve(root->left);
    int y = solve(root->right);
    if (abs(x - y) > 1)
        f = 0;
    return (max(x, y) + 1);
}
bool isBalanced(Node *root)
{
    f = 1;
    solve(root);
    return f;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->left->left = new Node(8); // include this ans 0 and if excluded the ans is 1;

    cout<<isBalanced(root);

    return 0;
}

