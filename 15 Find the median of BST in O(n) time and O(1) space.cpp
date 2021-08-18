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
void inor(bst *root, int &n)
{
    if (!root)
        return;
    inor(root->left, n);
    n++;
    inor(root->right, n);
}

void solve(bst *root, bst *&prev, bst *&curr, int &c, int x, int &f)
{
    if (!root)
        return;
    solve(root->left, prev, curr, c, x, f);
    if (prev == NULL)
    {
        prev = root;
        c++;
    }
    else if (x == c)
    {
        curr = root;
        c++;
        f = 1;
        return;
    }
    else if (f == 0)
    {
        prev = root;
        c++;
    }
    solve(root->right, prev, curr, c, x, f);
}

float findMedian(bst *root)
{
    int n = 0;
    inor(root, n);
    bst *prev = NULL;
    bst *curr = NULL;
    int f = 0;
    int x = (n / 2) + 1;
    int c = 1;
    solve(root, prev, curr, c, x, f);

    if (n & 1)
    {
        float ans = (curr->data) * 1.0;
        return ans;
    }
    else
    {
        float ans = ((curr->data + prev->data) * 1.0) / (2 * 1.0);
        return ans;
    }
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
    bst *root = new bst(6); //for even length ans is 5 as (n/2 + (n/2 + 1))
    root->left = new bst(3);
    root->right = new bst(8);
    root->left->left = new bst(1);
    root->left->right = new bst(4);
    root->right->left = new bst(7);
    inorder(root);
    cout << endl;
    cout << findMedian(root);
}

/*

bst *root = new bst(6); //for odd length ans is 6  as (n/2 + 1)
    root->left = new bst(3);
    root->right = new bst(8);
    root->left->left = new bst(1);
    root->left->right = new bst(4);
    root->right->left = new bst(7);
    root->right->right = new bst(9);
    inorder(root);
    cout << endl;
    cout << findMedian(root);

*/
