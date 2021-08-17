#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(h), Space Complexity: O(h)

struct bst
{
    int data = 0;
    bst *left = NULL, *right = NULL;
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

bst *LCA(bst *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (n1 > root->data and n2 > root->data)
        LCA(root->right, n1, n2);
    else if (n1 < root->data and n2 < root->data)
        LCA(root->left, n1, n2);
    else
        return root;
}

int main()
{
    bst *root = NULL;
    root = insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    bst *ans = LCA(root, 7, 8);
    cout << ans->data;
}

/*
ans = 7
*/
