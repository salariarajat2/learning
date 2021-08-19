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

bool solve(bst *root, int min, int max)
{
    if (!root)
        return false;
    if (min == max)
        return true;

    return solve(root->left, min, root->data - 1) or solve(root->right, root->data + 1, max);
}

void is_dead_end(bst *root)
{
    solve(root, 1, INT_MAX) ? cout << "Yes" : cout << "NO";
}

int main()
{
    bst *root = new bst(8);
    root->left = new bst(7);
    root->right = new bst(10);
    root->left->left = new bst(2);
    root->right->left = new bst(9);  //include this result dead end else no dead end is present 
    root->right->right = new bst(13);

    is_dead_end(root);
}

