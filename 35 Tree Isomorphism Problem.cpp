#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(min(M,N) //sizes of trees, Auxiliary Space: O(min(h1,h2)

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
bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 and !root2)
        return true;
    if (!root1 or !root2)
        return false;
    if (root1->data != root2->data)
        return false;
    bool a = (isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right));
    bool b = (isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left));
    return a or b;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(4);

    int a = 2, b = 3;
    cout << isIsomorphic(root1,root2);
}

