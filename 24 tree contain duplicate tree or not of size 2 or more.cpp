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

unordered_map<string, int> mp;
string solve(Node *root)
{
    if (!root)
        return "$";
    string s="";
    if (!root->left and !root->right) //mention not to take the string of size 1. so, leaf not included
    {
        s = to_string(root->data);
        return s;
    }

    s = to_string(root->data);
    s += solve(root->left);
    s += solve(root->right);
    mp[s]++;
    return s;
}

bool check(Node *head)
{
    mp.clear();
    solve(head);
    for (auto it : mp)
    {
        if (it.second > 1)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4); 
    head->left->right = new Node(5);
    head->right->right = new Node(2);
    head->right->right->left = new Node(4);
    head->right->right->right = new Node(5);

    cout << check(head);
}

/*
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

ans= 1

*/
