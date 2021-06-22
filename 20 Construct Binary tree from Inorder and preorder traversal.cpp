#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(n)    

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

unordered_map<int, int> mp;
int idx = 0;

Node *bt(int *in, int *pre, int lb, int ub)
{

    if (lb > ub)
        return NULL;
    Node *head = new Node(pre[idx++]);

    if (ub == lb)
        return head;

    int mid = mp[head->data];
    head->left = bt(in, pre, lb, mid - 1);
    head->right = bt(in, pre, mid + 1, ub);
}

Node *buildTree(int in[], int pre[], int len)
{
    mp.clear();
    for (int i = 0; i < len; i++)
    {
        mp[in[i]] = i;
    }
    return bt(in, pre, 0, len - 1);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    int N = 6;
    int in[N] = {3, 1, 4, 0, 5, 2};
    int pre[N] = {0, 1, 3, 4, 2, 5};

    Node *curr = buildTree(in, pre, N);
    postorder(curr);
}

/*
ans = 3 4 1 5 2 0
*/ 


/*
//Time Complexity: O(n^2), Space Complexity: O(1)    

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

Node *buildTreee(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    Node *tNode = new Node(pre[preIndex++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTreee(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTreee(in, pre, inIndex + 1, inEnd);

    return tNode;
}

*/
