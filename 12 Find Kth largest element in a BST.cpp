#include <bits/stdc++.h>
using namespace std;

// TC = O(K) , SC = O (h)

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

int ans;

void solve(bst *root, int &idx, int k)
{
    if (!root)
        return;
    solve(root->right, idx, k);
    if (idx == k)
    {
        ans = root->data;
        idx++;
        return;
    }
    else
        idx++;
    solve(root->left, idx, k);
}

void kthsmallest(bst *root, int k)
{
    ans = -1;
    int idx = 1;
    solve(root, idx, k);
    cout << ans;
}

bst *insert(bst *root, int val)
{
    if (!root)
    {
        bst *temp = new bst(val);
        return temp;
    }

    if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
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
    root = insert(root, 2);
    insert(root, 1);
    insert(root, 100);
    insert(root, 50);
    insert(root, 10);
    insert(root, 8);
    insert(root, 300);

    inorder(root);
    cout << endl;
    kthsmallest(root, 3);
}
