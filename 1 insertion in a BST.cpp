#include <iostream>
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
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 60);
    insert(root, 80);
    insert(root, 70);
    insert(root, 40);
    inorder(root);
}


/*
20
30
40
50
60
70
80
*/
