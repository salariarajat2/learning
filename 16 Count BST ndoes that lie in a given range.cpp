#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC = O (1)

class bst
{
public:
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

int getCount(bst *root, int l, int h)
{
    if (!root)
        return 0;

    if (root->data >= l and root->data <= h)
    {
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }
    else if (root->data < l)
    {
        return getCount(root->right, l, h);
    }
    else
    {
        return getCount(root->left, l, h);
    }
}

int main()
{
    bst *root = new bst(10); //for even length ans is 5 as (n/2 + (n/2 + 1))
    root->left = new bst(5);
    root->right = new bst(50);
    root->left->left = new bst(1);
    root->right->left = new bst(40);
    root->right->right = new bst(100);

    cout << getCount(root, 5, 45);
}



/*
void solve(bst *root, int l, int h, int &cnt)
{
    if (!root)
        return;
    solve(root->left, l, h, cnt);
    if (root->data >= l and root->data <= h)
    {
        ++cnt;
    }
    solve(root->right, l, h, cnt);
}

int getCount(bst *root, int l, int h)
{
    int cnt = 0;
    solve(root, l, h, cnt);
    return cnt;
}

*/


