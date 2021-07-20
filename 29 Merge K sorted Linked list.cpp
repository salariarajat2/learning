#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nk logk), Auxiliary Space: O(1)

struct Node
{
    int data;
    struct Node *next;
};

Node *merge(Node *a, Node *b)
{
    Node *answer = NULL;

    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a->data < b->data)
    {
        answer = a;
        answer->next = merge(a->next, b);
    }
    else
    {
        answer = b;
        answer->next = merge(a, b->next);
    }

    return answer;
}

Node *mergeKLists(Node *arr[], int k)
{
    int i = 0, last = k - 1, j = 0;
    while (last != 0)
    {
        i = 0;
        j = last;
        while (i < j)
        {
            arr[i] = merge(arr[i], arr[j]);
            i++;
            j--;
            last = (i >= j) ? j : last;
        }
    }
    return arr[0];
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int k = 3;
    int n = 4;
    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
    Node *head = mergeKLists(arr, k);
    printList(head);

    return 0;
}

/*
//Using priority queue
//Time Complexity: O(nk logk), Space Complexity: O(k)

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

struct Node *mergeKSortedLists(
    struct Node *arr[], int k)
{
    struct Node *head = NULL, *last;

    priority_queue<Node *, vector<Node *>, compare> pq;
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

    while (!pq.empty())
    {
        Node *top = pq.top();
        pq.pop();
        if (top->next != NULL)
            pq.push(top->next);

        if (head == NULL)
        {
            head = top;
            last = top;
        }

        else
        {
            last->next = top;
            last = top;
        }
    }
    return head;
}
*/
