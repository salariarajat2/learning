#include <bits/stdc++.h>
using namespace std;

// TC = O (N^2)

vector<int> find(vector<int> ans, int x)
{
    int carry = 0;
    vector<int> v;
    for (int i = 0; i < ans.size(); i++)
    {
        int val = x * ans[i] + carry;
        v.push_back(val % 10);
        carry = val / 10;
    }
    while (carry)
    {
        v.push_back(carry % 10);
        carry = carry / 10;
    }

    return v;
}

vector<int> factorial(int N)
{
    // code here

    vector<int> ans;
    ans.push_back(1);
    if (N == 0)
        return ans;
    for (int i = 2; i <= N; i++)
    {
        ans = find(ans, i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> result = factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

void Multiply(Node *tail, int n)
{
    Node *temp = tail,*nextNode = tail;
    int carry = 0;
    while (temp != NULL)
    {
        int data = temp->data * n + carry;
        temp->data = data % 10;
        carry = data / 10;
        nextNode = temp;
        temp = temp->next;
    }
    while (carry != 0)
    {
        nextNode->next = new Node((int)(carry % 10));
        carry /= 10;
        nextNode = nextNode->next;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
        return;
    print(tail->next);
    cout << tail->data;
}

int main()
{
    int n = 20;
    Node tail(1);
    for (int i = 2; i < n; i++)
        Multiply(&tail, i);
    print(&tail);
    cout << endl;
    return 0;
}


*/