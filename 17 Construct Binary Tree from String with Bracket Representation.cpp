#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2), Auxiliary Space: O(N)

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

Node *tree(string s, int *start)
{
    if (s.size() == 0 || *start >= s.size())
        return NULL;

    int num = 0;
    while (*start < s.size() && s[*start] != '(' && s[*start] != ')')
    {
        num = (s[*start] - '0'); //(int)
        *start = *start + 1;
    }

    Node *root = new Node(num);

    if (*start >= s.size()) // check if start has reached the end of the string
        return root;

    if (*start < s.size() && s[*start] == '(') //construct the tree in the left
    {
        *start = *start + 1;
        root->left = tree(s, start);
    }

    if (*start < s.size() && s[*start] == '(') //construct the tree in the right
    {
        *start = *start + 1;
        root->right = tree(s, start);
    }
    
    if (*start < s.size() && (s[*start] == ')' or s[*start] == ')'))
        *start = *start + 1;

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    string s = "4(2(3)(1))(6(5))";
    int start = 0;
    Node *root = tree(s, &start);
    preorder(root);
    return 0;
}

/*
ans = 4 2 3 1 6 5
*/









/*
Node *tree(string s, int *start)
{
    if (s.size() == 0 || *start >= s.size())
        return NULL;

    int num = 0;
    while (*start < s.size() && s[*start] != '(' && s[*start] != ')')
    {
        num = (s[*start] - '0'); //(int)
        *start = *start + 1;
    }

    Node *root = new Node(num);

    if (*start >= s.size()) // check if start has reached the end of the string
        return root;

    if (*start < s.size() && s[*start] == '(') //construct the tree in the left
    {
        *start = *start + 1;
        root->left = tree(s, start);
    }

    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;

    if (*start < s.size() && s[*start] == '(') //construct the tree in the right
    {
        *start = *start + 1;
        root->right = tree(s, start);
    }

    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;

    return root;
}
*/








/*
// Time Complexity: O(N^2), Auxiliary Space: O(N)

int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;

    stack<char> s;

    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);

        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

Node *treeFromString(string str, int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;

    Node *root = newNode(str[si] - '0');
    int index = -1;

    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);

    if (index != -1)
    {
        root->left = treeFromString(str, si + 2, index - 1);
        root->right = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}

*/
