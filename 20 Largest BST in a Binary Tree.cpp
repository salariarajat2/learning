#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(Height of the BST).

struct bst
{
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

vector<int> solve(bst *root)
{
    if (!root)
        return {1, 0, INT_MAX, INT_MIN};
    if (!root->left and !root->right)
        return {1, 1, root->data, root->data};

    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);

    if (l[0] and r[0])
    {
        if (root->data > l[3] and root->data < r[2])
        {
            int x = l[2];
            int y = r[3];
            if (x == INT_MAX)
                x = root->data;
            if (y == INT_MIN)
                y = root->data;

            return {1, l[1] + r[1] + 1, x, y};
        }
    }
    return {0, max(l[1], r[1]), 0, 0};
}

void largestbst(bst *root)
{
    vector<int> ans = solve(root);
    cout << ans[1];
}

int main()
{
    bst *root = new bst(1);
    root->left = new bst(4);
    root->right = new bst(4);
    root->left->left = new bst(6);
    root->left->right = new bst(8);
    largestbst(root);
}
