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

bst *in(bst *root) //finding successor
{
    bst *t = root->right;
    while (t->left)
        t = t->left;
    return t;
}

bst *del(bst *root, int value)
{
    if (!root)
        return NULL;
    if (value < root->data)
        root->left = del(root->left, value);
    else if (value > root->data)
        root->right = del(root->right, value);
    else
    {
        if (!root->left)
        {
            bst *temp = root->right;
            delete (root);
            return temp;
        }
        if (!root->right)
        {
            bst *temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            bst *temp = in(root);
            swap(root->data, temp->data);
            root->right = del(root->right, value);
        }
    }
    return root;
}

void inorder(bst *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    bst *root = NULL;
    root = insert(root, 10);
    insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    inorder(root);
    cout << endl;
    bst *ans = del(root, 50);
    cout << ans->data;
    cout << endl;
    inorder(ans);
}

/*
ans=

10 20 30 40 50 60 70
10
10 20 30 40 60 70

*/
