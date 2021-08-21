#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(Height of the BST).

struct bst
{
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
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
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

void inorder(bst *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    inorder(root->right);
}

void solve(bst *root, bst *&temp)
{
    if (!root)
        return;
    solve(root->left, temp);
    temp->left = NULL;
    temp->right = root;
    temp = root;
    solve(root->right, temp);
}

bst *flattern(bst *root)
{
    bst *temp = new bst(-1);
    bst *re = temp;
    solve(root, temp);
    temp->left = NULL;
    temp->right = NULL;

    bst *ans = re->right;
}

int main()
{
    bst *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    bst *a = flattern(root);
    inorder(a);
}
