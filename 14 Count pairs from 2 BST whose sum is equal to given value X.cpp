#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(size of first tree * hieght of second tree), Space Complexity: O(1)

class bst
{
public:
    int data;
    bst *left = NULL, *right = NULL;
    bst(int val)
    {
        data = val;
    }
};

int c;
vector<vector<int>> ans;

bool solve1(bst *root, int i)
{
    if (!root)
        return false;
    if (root->data == i)
        return true;

    bool x = false, y = false;
    if (root->data < i)
        y = solve1(root->right, i);
    else if (root->data > i)
        x = solve1(root->left, i);
    return x or y;
}

void solve(bst *root1, bst *root2, int x)
{
    if (!root1)
        return;
    solve(root1->left, root2, x);
    if (solve1(root2, x - root1->data))
    {
        ans.push_back({root1->data, x - root1->data});
        c++;
    }
    solve(root1->right, root2, x);
}

int countPairs(bst *root1, bst *root2, int x)
{
    c = 0;
    solve(root1, root2, x);
    return c;
}

int main()
{
    bst *root1 = new bst(5);
    root1->left = new bst(3);
    root1->right = new bst(7);
    root1->left->left = new bst(2);
    root1->left->right = new bst(4);
    root1->right->left = new bst(6);
    root1->right->right = new bst(8);

    bst *root2 = new bst(10);
    root2->left = new bst(6);
    root2->right = new bst(15);
    root2->left->left = new bst(3);
    root2->left->right = new bst(8);
    root2->right->left = new bst(11);
    root2->right->right = new bst(15);

    cout << countPairs(root1, root2, 16);
    cout << endl;
    for (auto it : ans)
    {
        for (auto a : it)
        {
            cout << a << "  ";
        }
        cout << endl;
    }
}
