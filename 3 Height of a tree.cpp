#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int maxDepth(Node *root)
{
    if (!root)
        return 0;

    int x = maxDepth(root->right);
    int y = maxDepth(root->left);
    return ((x > y ? x : y) + 1);   //return (max(x,y) + 1);
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

    cout << "Height of tree is " << maxDepth(root);
    return 0;
}

/*

int maxDepth(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int x = maxDepth(node->left);
        int y = maxDepth(node->right);

        if (x > y)
            return (x + 1);
        else
            return (y + 1);
    }
}
*/

