#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(h)

struct bst
{
    int data = 0;
    bst *left = NULL, *right = NULL, *next = NULL;
    bst(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bst *insert(bst *root, int val)
{
    if (!root)
    {
        bst *temp = new bst(val);
        return temp;
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

void inord(bst *root, bst *&temp)
{
    if (!root)
        return;
    inord(root->left, temp);
    if (temp != NULL)
    {
        temp->next = root;
    }
    temp = root;
    inord(root->right, temp);
}

void populate_inorder_successor(bst *root)
{
    bst *temp = NULL;
    inord(root, temp);
}

void inorder(bst *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " -> ";
    root->next ? cout << root->next->data : cout << "-1";
    cout << endl;
    inorder(root->right);
}

int main()
{
    bst *root = NULL;
    root = insert(root, 10);
    insert(root, 8);
    insert(root, 3);
    insert(root, 12);
    populate_inorder_successor(root);
    inorder(root);
}

/*
ans =

3 -> 8
8 -> 10
10 -> 12
12 -> -1
*/
