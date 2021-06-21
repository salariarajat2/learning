#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(n)

struct Node
{
    int data;
    Node *left, *right;
    Node(int key)
    {
        data = key;
        this->left = this->right = NULL;
    }
};

void topView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    if (!root)
        return;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();
        if (!mp[h])
            mp[h] = curr->data;
        if (curr->left)
            q.push({curr->left, h - 1});
        if (curr->right)
            q.push({curr->right, h + 1});
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
}
int main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);

    topView(head);
}

/*
ans= 20 10 30 
*/




/*
//Time Complexity: O(n logn), Space Complexity: O(n)

void fillMap(Node *root, int d, int l, map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;

    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l)
    {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}

void topView(struct Node *root)
{
    map<int, pair<int, int>> m;
    fillMap(root, 0, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second.first << " ";
    }
}

*/
