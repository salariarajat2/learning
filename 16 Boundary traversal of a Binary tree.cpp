#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(h)

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
void left(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (root->left)
    {
        ans.push_back(root->data);
        left(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        left(root->right, ans);
    }
}
void leaf(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    leaf(root->left, ans);
    if (!root->left and !root->right)
        ans.push_back(root->data);
    leaf(root->right, ans);
}
void right(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (root->right)
    {
        right(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        right(root->left, ans);
        ans.push_back(root->data);
    }
}
void printBoundary(Node *root)
{
    vector<int> ans;
    if (!root)
        return;
    ans.push_back(root->data);
    left(root->left, ans);
    leaf(root, ans);
    right(root->right, ans);
    
    for(auto v : ans)
    {
        cout<<v<<" ";
    }
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
    root->right->left->left->left = new Node(9);
    root->right->left->left->right = new Node(10);
    printBoundary(root);

    return 0;
}

/*
ans = 1 2 4 9 10 8 6 3 
*/


