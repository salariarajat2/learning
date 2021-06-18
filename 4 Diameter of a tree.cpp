#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(Height of the Tree).

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int ma;
int fun(Node *root)
{
    if (!root)
        return 0;
    int x = fun(root->left);
    int y = fun(root->right);
    ma = max(ma, x + y + 1);
    return (max(x, y) + 1);
}

int diameter(Node *root)
{
    ma = INT_MIN;
    fun(root);
    return ma;
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Diameter of the given binary tree is " << diameter(root);
    return 0;
}

/*
Time Complexity: O(n^2)

int height(Node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct node* tree)
{
    if (tree == NULL)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
*/
