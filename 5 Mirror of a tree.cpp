#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Auxiliary Space: O(Height of the Tree).

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

void inorder(Node *root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void mirror(Node *root)
{
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

int main()
{
    Node *tree = newNode(5);
    tree->left = newNode(3);
    tree->right = newNode(6);
    tree->left->left = newNode(2);
    tree->left->right = newNode(4); 
    cout << "Inorder of original tree ";
    inorder(tree);

    mirror(tree);

    cout <<endl<< "Inorder of mirror tree ";
    inorder(tree);
    return 0;
}

/*
treenode* mirrorTree(node* root)
{
    // Base Case
    if (root == NULL)
        return root;
    swap(root->left,root->right);
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}
*/

/*
Time Complexity: O(n) , Space Complexity = O(n)

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void mirrorify(node *root, node **mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }

    *mirror = newNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}
*/
