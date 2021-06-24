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

void fun(Node *root, vector<int> &ans, int k)
{
    if (!root)
        return;

    ans.push_back(root->data);
    fun(root->left, ans, k);
    fun(root->right, ans, k);

    int f = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        f += ans[i];
        if (f == k)
        {
            for (int j = i; j < ans.size(); j++)
            {
                cout << ans[j] << " ";
            }
            cout << endl;
        }
    }
    ans.pop_back();
}

void printKPath(Node *root, int k)
{
    if (!root)
        cout << "NULL";
    vector<int> ans;
    fun(root, ans, k);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);
}

/*
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    


ans =   3 2
        3 1 1
        1 3 1
        4 1
        1 -1 4 1
        -1 4 2
        5
        1 -1 5
*/

/*
*/
