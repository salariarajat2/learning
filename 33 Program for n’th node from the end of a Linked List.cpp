#include<bits/stdc++.h>
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

int getNthFromLast(Node *head, int n)
{
    int len = 0, i;
    struct Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    if (len < n)
        return -1;

    temp = head;

    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;

    return temp->data;
}

int main()
{
    int K, n;
    cin >> K >> n;
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

    cout << getNthFromLast(head, n) << endl;
}


/*
7 2
17 15 8 9 2 4 6
ans = 4
*/

/*
Node *r(Node *head)
{
    Node *curr=head,*prev=NULL;
    while(curr)
    {
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int getNthFromLast(Node *head, int n)
{
    int a=0;
    Node *curr=head;
    while(curr)
    {
        curr=curr->next;
        a++;
    }
    
    if(a < n) return -1;
    
    else
    {
    head=r(head);
       while(--n)
      {
          head=head->next;
      }
      return head->data; 
    }
}
*/


