#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

void func(int &pre, int n, int min, int max, int *a)
{
    if (pre == n)
        return;

    if (a[pre] >= min and a[pre] <= max)
    {
        int r = a[pre];
        pre++;
        func(pre, n, min, r, a);
        func(pre, n, r, max, a);
        cout<<r<<" ";
    }
}

bool canRepresentBST(int *a, int n)
{
    int min = INT_MIN, max = INT_MAX;
    int pre = 0;
    func(pre, n, min, max, a);
    return pre == n;
}

int main()
{

    int preorder1[] = {40 ,30 ,35 ,80 ,100};
    int n1 = sizeof(preorder1) / sizeof(preorder1[0]);

    if (canRepresentBST(preorder1, n1))
        cout << "\npreorder1 can represent BST";
    else
        cout << "\npreorder1 can not represent BST :(";
}


/*

struct node
{
    int data;
    struct node *left, *right;
};
void insert(node **root, int val)
{
    node *p = *root;
    if (p == NULL)
    {
        node *q;
        q = new node[1];
        q->data = val;
        q->left = q->right = NULL;
        *root = q;
    }
    else if (p->data > val)
    {
        insert(&p->left, val);
    }
    else if (p->data < val)
    {
        insert(&p->right, val);
    }
}
void postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
bool checkbst(int pre[], int n)
{
    stack<int> s;

    int root = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        if (pre[i] < root)
            return false;

        while (!s.empty() && s.top() < pre[i])
        {
            root = s.top();
            s.pop();
        }

        s.push(pre[i]);
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, *a;
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            insert(&root, a[i]);
        }
        bool y = checkbst(a, n);
        if (y == true)
        {
            postorder(root);
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    //code
    return 0;
}
*/




/*
#include <bits/stdc++.h>
using namespace std;

bool canRepresentBST(int pre[], int n)
{
    stack<int> s;
    int root = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (pre[i] < root)
            return false;

        while (!s.empty() && s.top() < pre[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1) / sizeof(pre1[0]);
    canRepresentBST(pre1, n) ? cout << "true\n" : cout << "false\n";
}
*/

