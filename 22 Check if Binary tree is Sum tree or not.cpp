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

int f = 1;
int solve(Node *root)
{
    if (!root)
        return 0;
    if (!root->left and !root->right)
        return root->data;
    if (f == 0)
        return 0;
    int a = solve(root->left);
    int b = solve(root->right);

    if (root->data != a + b)
        f = 0;

    return (a + b + root->data);
}

bool isSumTree(Node *root)
{
    f = 1;
    solve(root);
    return f;
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(10);
    head->left->right = new Node(10);

    cout<<isSumTree(head);
}

/*
          10
        /    \
      20      30
    /   \ 
   10    10

ans= 0

*/
