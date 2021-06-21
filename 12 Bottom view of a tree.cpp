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
    head->left->left = new Node(40);
    head->left->right = new Node(60);

    topView(head);
}

/*
ans= 40 20 60 30 
*/

/*
//Time Complexity: O(?), Space Complexity: O(n)

void printBottomViewUtil(Node *root, int curr, int hd, map<int, pair<int, int>> &m)
{

    if (root == NULL)
        return;

    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root->data, curr);
    }

    else
    {
        pair<int, int> p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root->data;
        }
    }

    printBottomViewUtil(root->left, curr + 1, hd - 1, m);
    printBottomViewUtil(root->right, curr + 1, hd + 1, m);
}

void printBottomView(Node *root)
{
    map<int, pair<int, int>> m;
    printBottomViewUtil(root, 0, 0, m);
    map<int, pair<int, int>>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair<int, int> p = it->second;
        cout << p.first << " ";
    }
}

*/
