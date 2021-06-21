#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(n)

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

void zigZagTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;
        int a = q.size();
        while (a--)
        {
            Node *curr = q.front();
            temp.push_back(curr->data);
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (!(f & 1))
            reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        f = !f;
    }
}

void simpleTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int a = q.size();
        while (a--)
        {
            Node *curr = q.front();
            temp.push_back(curr->data);
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
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
    simpleTraversal(root);
    cout << endl;
    zigZagTraversal(root);

    return 0;
}
/*
ans = 1 2 3 4 5 6 7 8 
1 3 2 4 5 6 8 7
*/
