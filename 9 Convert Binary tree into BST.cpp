#include <bits/stdc++.h>
using namespace std;

// TC = O(n logn) , SC = O(n)

struct bst
{
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

void in_tree(bst *root, vector<int> &v)
{
    if (!root)
        return;
    in_tree(root->left, v);
    v.push_back(root->data);
    in_tree(root->right, v);
}

void tree_to_bst(bst *root, vector<int> &v, int &i)
{
    if (!root)
        return;
    tree_to_bst(root->left, v, i);
    root->data = v[i++];
    tree_to_bst(root->right, v, i);
}

bst *tree_bst(bst *root)
{
    vector<int> v;
    int i = 0;
    in_tree(root, v);
    sort(v.begin(), v.end());
    tree_to_bst(root, v, i);
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
    bst *root = NULL; //creating tree
    root = new bst(1);
    root->left = new bst(2);
    root->left->left = new bst(4);
    root->right = new bst(3);
    cout << "inorder traversal of tree  ";
    inorder(root);
    cout << "\n";
    cout << "inorder traversal of bst is   ";
    inorder(tree_bst(root));
    return 0;
}

/*

inorder traversal of tree  4 2 1 3
inorder traversal of bst is   1 2 3 4

*/

