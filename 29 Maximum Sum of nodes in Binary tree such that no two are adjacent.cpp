#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(h)

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

unordered_map<Node *, int> dp;
int func(Node *root)
{
    if (!root)
        return 0;

    if (dp[root])
        return dp[root];
    int inc = root->data;
    if (root->left)
    {
        inc += func(root->left->left);
        inc += func(root->left->right);
    }
    if (root->right)
    {
        inc += func(root->right->left);
        inc += func(root->right->right);
    }

    int exc = func(root->left) + func(root->right);

    dp[root] = max(inc, exc);

    return dp[root];
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);

    cout << func(root);
}

/*
ans = 21
*/

/*
pair<int, int> maxSumHelper(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;

    // This node is included (Left and right children
    // are not included)
    sum.first = sum1.second + sum2.second + root->data;

    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);

    return sum;
}

int maxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}
*/
