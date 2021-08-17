#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

struct bst
{
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

bst *constructTreeUtil(int pre[], int *preIndex, int key, int min, int max, int size)
{
    if (*preIndex >= size)
        return NULL;

    bst *root = NULL;

    if (key > min && key < max)
    {
        root = new bst(key);
        *preIndex += 1;

        if (*preIndex < size)
        {
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size)
        {
            root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }

    return root;
}

bst *constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

void inorder(bst *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main()
{
    int pre[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(pre) / sizeof(pre[0]);

    bst *root = constructTree(pre, size);
    inorder(root);

    return 0;
}

/*
1 5 7 8 10 12 
*/


















/*

Time Complexity: O(n2) , Space Complexity: O(1)

bst *solve1(vector<int> bt, int &a, int low, int high)
{
    if (a >= bt.size() or low > high)
        return NULL;

    bst *root = new bst(bt[a]);
    a += 1;
    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; i++)
    {
        if (bt[i] > root->data)
            break;
    }

    root->left = solve1(bt, a, a, i - 1);
    root->right = solve1(bt, a, i, high);

    return root;
}

bst *solve(vector<int> bt)
{
    int a = 0;
    return solve1(bt, a, 0, bt.size() - 1);
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
    vector<int> bt =  { 10, 5, 1, 7, 40, 50 };
    bst *root = NULL;
    root = solve(bt);
    inorder(root);
}
*/



