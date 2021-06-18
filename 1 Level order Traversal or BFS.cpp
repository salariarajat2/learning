#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(n)

struct Node
{
    int data;
    struct Node *left, *right;
};

void printLevelOrder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        cout << curr->data << "  ";
    }
}

Node *newNode(int key)
{
    Node *temp = (Node *)malloc(sizeof(Node)); //Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}

/*
Time Complexity: O(n^2), Space Complexity: O(n)


void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void printLevelOrder(node *root)//call first
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
*/
