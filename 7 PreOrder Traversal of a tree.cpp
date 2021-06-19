#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)    //PreOrder Traversal (Root Left Right)

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

void preorder(Node *root)
{
    if(!root) return;

    cout<<root->data<<" ";
    if(root->left) preorder(root->left);
    if(root->right) preorder(root->right);
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

    preorder(root);

    return 0;
}
/*

/* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    
    
ans = 1 2 4 3 5 7 8 6
*/

/*
//Iterative Method
//Time Complexity: O(n), Space Complexity: O(n)

void preorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}
*/
