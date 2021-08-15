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

void inorder(bst *root, bst *&temp, int &f)
{
    if (!root)
        return;
    inorder(root->left, temp, f);
    if (temp != NULL and root->data <= temp->data)
    {
        f = 0;
        return;
    }
    temp = root;
    inorder(root->right, temp, f);
}

bool isbst(bst *root)
{
    int f = 1;
    bst *temp = NULL;
    inorder(root, temp, f);
    return f;
}

bst *inset(int val)
{
    bst *temp = new bst(val);
    return temp;
}

int main()
{
    bst *root = inset(20);
    root->left = inset(30);
    root->right = inset(10); //0

    // bst *root = inset(30);
    // root->left = inset(20);
    // root->right = inset(40); //1

    cout << isbst(root);
}
