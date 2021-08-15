#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(h), Space Complexity: O(1)

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

bst *search(bst *root, int val)
{
    if ((!root) or (root->data == val))
    {
        return root;
    }
    if (val > root->data)
    {
        return search(root->right, val);
    }
    if (val < root->data)
    {
        return search(root->left, val);
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
    if (search(root, 90))
    {
        cout << "data " << root->data << " is found";
    }
    else
    {
        cout << "data not found";
    }
}
