#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(n)

struct Node
{
    int data;
    struct Node *left, *right;
};

void reverseLevelOrder(Node *root)
{
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);
        if (root->right)
            q.push(root->right);

        if (root->left)
            q.push(root->left);
    }

    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
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
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    cout << "Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
    return 0;
}


/*
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->right)
            q.push(curr->right);
        if (curr->left)
            q.push(curr->left);
        ans.push_back(curr->data);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
*/









/*

Time Complexity : O(n ^ 2), Space Complexity : O(n)

void printGivenLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
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
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void reverseLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}

*/
