#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)    //PostOrder Traversal (Left Right Root)

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

void inorder(Node *root)
{
    if(!root) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
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

    inorder(root);

    return 0;
}
/*
ans = 4 2 7 8 5 6 3 1 
*/

/*
//Iterative Method
//Time Complexity: O(n), Space Complexity: O(n)

void inorder(Node *root)
{
    stack<Node *> s;
    stack<int> out;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        out.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }

        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
*/
