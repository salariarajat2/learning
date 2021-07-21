#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

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

Node *compute(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *temp = compute(head->next);
    if (temp->data >= head->data)
        return temp;
    else
        head->next = temp;
    return head;
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

    Node *result = compute(head);
    print(result);
    cout << endl;
}

/*
8    
12 15 10 11 5 6 2 3

ans- 15 11 6 3 
*/

/*
//by reversing the list
// Time Complexity = O(N) , Space Complexity = O(1)

Node *r(Node *root)
{
    Node *curr = root;
    Node *prev = NULL;

    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *compute(Node *head)
{
    head = r(head);
    Node *curr = head;
    int ma = head->data;
    Node *p = head;
    head = head->next;

    while (head)
    {
        if (head->data >= ma)
        {
            ma = head->data;
            p = head;
            head = head->next;
        }
        else
        {
            p->next = head->next;
            head = p->next;
        }
    }

    head = r(curr);
    return head;
}
*/
