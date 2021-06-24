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

int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;

    int a = findLargestSubtreeSum(root->left);
    int b = findLargestSubtreeSum(root->right);
    int ma = max(ma, root->data + a + b);
    return a + b + root->data;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(-2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->right = new Node(2);
    head->right->left = new Node(-6);

    cout << findLargestSubtreeSum(head);
}

/*

int findLargestSubtreeSumUtil(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int currSum = root->key + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}

int findLargestSubtreeSum(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN;
    findLargestSubtreeSumUtil(root, ans);

    return ans;
}
*/
