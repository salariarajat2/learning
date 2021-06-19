#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(n)

struct Node
{
    int data;
    Node *left, *right;
    Node(int key)
    {
        data = key;
        this->left = this->right = NULL;
    }
};

void right(Node *root)
{
    queue<Node *> q;
    if (!root)
        return;
    q.push(root);
    while (!q.empty())
    {
        int a = q.size();
        Node *curr;
        while (a--)
        {
            curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << curr->data << " ";
    }
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(60);

    right(head);
}

/*
ans= 10 30 60 
*/
