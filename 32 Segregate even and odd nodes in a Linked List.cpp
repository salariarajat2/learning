#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *divide(Node *head)
{

    Node *even = NULL;
    Node *odd = NULL;
    Node *e = NULL;
    Node *o = NULL;

    while (head)
    {
        if ((head->data) & 1)
        {
            if (!odd)
            {
                odd = head;
                o = head;
            }
            else
            {
                o->next = head;
                o = o->next;
            }
        }
        else
        {
            if (!even)
            {
                even = head;
                e = head;
            }
            else
            {
                e->next = head;
                e = e->next;
            }
        }
        head = head->next;
    }

    if (e)
        e->next = odd;
    if (o)
        o->next = NULL;
    if (even)
        return even;
    else
        return odd;
}

int main()
{
    int K;
    cin >> K;
    Node *head = NULL;
    Node *temp;

    for (int i = 0; i < K; i++)
    {
        int data;
        cin >> data;
        if (head == NULL)
        {
            head = temp = new Node(data);
        }
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    Node *result = divide(head);
    print(result);
    cout << endl;
}

/*
6
10 22 30 43 56 70 

ans = 8 2 4 6 17 15 9 
*/
