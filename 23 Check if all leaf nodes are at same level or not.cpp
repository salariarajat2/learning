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

int ans;

void solve(Node *root, int h, int &ma)
{
    if (!root)
        return;
    if (!root->left and !root->right)
    {
        if (ma == -1)
            ma = h;
        else
        {
            if (ma != h)
            {
                ans = 0;
            }
            return;
        }
    }
    solve(root->left, h + 1, ma);
    solve(root->right, h + 1, ma);
}

bool check(Node *head)
{
    int h = 0;
    int ma = -1;
    ans = 1;
    solve(head, h, ma);
    return ans;
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(10);
    head->left->right = new Node(10);

    cout << check(head);
}

/*
          10
        /    \
      20      30
    /   \ 
   10    10

ans= 0 // 30 is not in the same leve

*/
