#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), Auxiliary Space: O(n)

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

string func(Node *root, unordered_map<string, int> &mp)
{
    if (!root)
        return "";

    string s = "";

    s += func(root->left, mp);
    s += to_string(root->data);
    s += func(root->right, mp);

    if (mp[s] == 1)
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    mp[s]++;
    return s;
}
void printallDups(Node *root)
{
    unordered_map<string, int> mp;
    func(root, mp);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);

    printallDups(root);

    return 0;
}

