#include <bits/stdc++.h>
using namespace std;

// TC = O(m+n) , SC = O (m + n)

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int *merge(int arr1[], int arr2[], int m, int n)
{
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i++];
        }
        else
        {
            mergedArr[k] = arr2[j++];
        }
        k++;
    }

    while (i < m)
    {
        mergedArr[k++] = arr1[i++];
    }

    while (j < n)
    {
        mergedArr[k++] = arr2[j++];
    }

    return mergedArr;
}

void storeInorder(node *node, int inorder[], int &index_ptr)
{
    if (node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);
    inorder[index_ptr++] = node->data;
    storeInorder(node->right, inorder, index_ptr);
}

node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

node *mergeTrees(node *root1, node *root2, int m, int n)
{
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, i);

    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, j);

    int *mergedArr = merge(arr1, arr2, m, n);
    return sortedArrayToBST(mergedArr, 0, m + n - 1);
}

void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);

    return 0;
}



/*

#include <bits/stdc++.h>
using namespace std;

// TC = O(m+n) , SC = O (m + n)

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

void inor(bst *root)
{
    if (!root)
        return;
    inor(root->left);
    cout << root->data << " ";
    inor(root->right);
}

vector<int> merge(vector<int> &a, vector<int> &b, int m, int n)
{
    vector<int> ans(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m and j < n)
    {
        if (a[i] < b[j])
        {
            ans[k] = a[i++];
        }
        else
        {
            ans[k] = b[j++];
        }
        k++;
    }
    while (i < m)
    {
        ans[k++] = a[i++];
    }
    while (j < n)
    {
        ans[k++] = a[j++];
    }

    return ans;
}

void inorder(bst *root, vector<int> &a)
{
    if (!root)
        return;
    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

bst *create_bst(vector<int> &final, int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    bst *root = new bst(final[mid]);

    root->left = create_bst(final, low, mid - 1);
    root->right = create_bst(final, mid + 1, high);

    return root;
}

bst *storein(bst *root1, bst *root2, int m, int n)
{
    vector<int> a1;
    inorder(root1, a1);

    vector<int> a2;
    inorder(root2, a2);

    vector<int> final(m + n);
    final = merge(a1, a2, m, n);

    return create_bst(final, 0, final.size() - 1);
}

int main()
{
    bst *root1 = new bst(100);
    root1->left = new bst(50);
    root1->right = new bst(300);
    root1->left->left = new bst(20);
    root1->left->right = new bst(70);

    bst *root2 = new bst(80);
    root2->left = new bst(40);
    root2->right = new bst(120);

    bst *root = storein(root1, root2, 5, 3);
    inor(root);
}

*/

