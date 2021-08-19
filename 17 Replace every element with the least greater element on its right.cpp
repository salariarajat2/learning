#include <bits/stdc++.h>
using namespace std;

// TC = O(n logn) , SC = O (1)

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

bst *solve(bst *root, int val, bst *&succ)
{
    if (!root)
    {
        return root = new bst(val);
    }
    if (root->data > val)
    {
        succ = root;
        root->left = solve(root->left, val, succ);
    }
    else if (root->data < val)
    {
        root->right = solve(root->right, val, succ);
    }
    return root;
}

int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};

    int n = sizeof(arr) / sizeof(arr[0]);

    bst *root = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        bst *succ = NULL;
        root = solve(root, arr[i], succ);
        if (succ)
        {
            arr[i] = succ->data;
        }
        else
        {
            arr[i] = -1;
        }
    }

    for (auto a : arr)
    {
        cout << a << " ";
    }
}

/*
ans = 18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1
*/

