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

vector<int> solve(Node *root)
{
    if (!root)
        return {0, 0};
    vector<int> a = solve(root->left);
    vector<int> b = solve(root->right);

    if (a[0] > b[0])
        return {a[0] + 1, a[1] + root->data};
    if (a[0] < b[0])
        return {b[0] + 1, b[1] + root->data};
    else
        return {a[0] + 1, max(a[1], b[1]) + root->data};
}
int sumOfLongRootToLeafPath(Node *root)
{
    vector<int> ans = solve(root);
    return ans[1];
}

int main()
{
    Node *head = new Node(4);
    head->left = new Node(2);
    head->right = new Node(5);
    head->left->left = new Node(7);
    head->left->right = new Node(1);
    head->left->right->left = new Node(6);
    head->right->right = new Node(3);
    head->right->left = new Node(2);

    cout << sumOfLongRootToLeafPath(head);
}

/*
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6

ans= 13
*/

/*
//BFS
// Time Complexity: O(N), Auxiliary Space: O(n)

int maxSumLevel = root->data, maxLevel = 0;

//    queue to implement level order traversal

list<Element> que;
Element e;

//    Each element variable stores the current Node, it's level, sum in the path

e.data = root;
e.level = 0;
e.sum = root->data;

//    push the root element
que.push_back(e);

//    do level order traversal on the tree
while (!que.empty())
{

    Element front = que.front();
    Node *curr = front.data;
    que.pop_front();

    //   if the level of current front element is greater than the maxLevel so far then update maxSum
    if (front.level > maxLevel)
    {
        maxSumLevel = front.sum;
        maxLevel = front.level;
    }
    //   if another path competes then update if the sum is greater than the previous path of same height
    else if (front.level == maxLevel && front.sum > maxSumLevel)
        maxSumLevel = front.sum;

    //   push the left element if exists
    if (curr->left)
    {
        e.data = curr->left;
        e.sum = e.data->data;
        e.sum += front.sum;
        e.level = front.level + 1;
        que.push_back(e);
    }
    //  push the right element if exists
    if (curr->right)
    {
        e.data = curr->right;
        e.sum = e.data->data;
        e.sum += front.sum;
        e.level = front.level + 1;
        que.push_back(e);
    }
}

//   return the answer
return maxSumLevel;
}
*/
