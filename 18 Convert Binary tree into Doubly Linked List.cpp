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

Node *solve(Node *root, Node *&head, Node *&prev, int &f)
{
    if (!root)
        return head;
    solve(root->left, head, prev, f);

    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = root;
    }
    solve(root->right, head, prev, f);
}

Node *bToDLL(Node *root)
{
    Node *head = NULL, *prev = NULL;
    int f = 0;
    solve(root, head, prev, f);
    return head;
}

void print(Node *head)
{
    Node *prev;
    while (head)
    {
        if (!head->right)
            prev = head;
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
    while (prev)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
}
int main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(60);

    Node *root = bToDLL(head);
    print(root);
}

/*
ans= 40 20 60 10 30
30 10 60 20 40
*/


/*
void aa(node *root, node **head)
{
    if (root == NULL)
        return;

    static node *prev = NULL;
    aa(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    aa(root->right, head);
}
*/






