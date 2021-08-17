#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC = O(n)

struct bst
{
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

void inorder(bst *root, vector<bst *> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}

bst *sol(vector<bst *> &in, int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    bst *root = in[mid];
    root->left = sol(in, low, mid - 1);
    root->right = sol(in, mid + 1, high);

    return root;
}

bst *buildTree(bst *root)
{
    vector<bst *> in;
    inorder(root, in);
    int a = in.size();
    return sol(in, 0, a - 1);
}

void preOrder(bst *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    bst *root = new bst(10);
    root->left = new bst(8);
    root->left->left = new bst(7);
    root->left->left->left = new bst(6);
    root->left->left->left->left = new bst(5);

    root = buildTree(root);

    printf("Preorder traversal of balanced "
           "BST is : \n");
    preOrder(root);

    return 0;
}


/*

Preorder traversal of balanced BST is : 
7 5 6 8 10 

*/


/*

A Simple Solution is to traverse nodes in Inorder and one by one insert into a self-balancing BST like AVL tree.
Time complexity of this solution is O(n Log n) and this solution doesn’t guarantee 

*/
