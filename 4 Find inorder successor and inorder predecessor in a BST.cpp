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
    else
    {
        root->left = insert(root->left, val);
    }
    return root;
}

bst *pra(bst *root) //predecessor => first left then extreme right
{
    bst *a = root->left;
    while (a->right)
        a = a->right;
    return a;
}
bst *su(bst *root) //successor => first right then extreme left
{
    bst *a = root->right;
    while (a->left)
        a = a->left;
    return a;
}

void findPreSuc(bst *root, bst *&pre, bst *&suc, int data)
{
    if (!root)
        return;
    if (data == root->data)
    {
        if (root->left)
            pre = pra(root);
        if (root->right)
            suc = su(root);
        return;
    }
    if (data > root->data)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, data);
    }
    else if (data < root->data)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, data);
    }
}

int main()
{
    bst *root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 60);
    insert(root, 80);
    insert(root, 70);
    insert(root, 40);
    bst *suc, *pre;
    int data = 30;
    findPreSuc(root, pre, suc, data);
    cout << pre->data << " " << suc->data;
}
