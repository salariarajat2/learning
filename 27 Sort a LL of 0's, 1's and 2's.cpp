#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

class Node
{
public:
    int data;
    Node *next;
};

void sortList(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;

    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

void push(Node **head, int key)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->next = (*head);
    (*head) = temp;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(void)
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    cout << "Linked List Before Sorting\n";
    printList(head);

    sortList(head);

    cout << "Linked List After Sorting\n";
    printList(head);

    return 0;
}

// This code is contributed by rathbhupendra

/*

Node *sortList(Node *head)
{
    if (!head || !(head->next))
        return head;

    Node *zeroD = newNode(0);
    Node *oneD = newNode(0);
    Node *twoD = newNode(0);

    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
            curr = curr->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }


    zero->next = (oneD->next)? (oneD->next): (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}
*/

/*
Node *segregate(Node *head)
{
    int a = 0, b = 0, c = 0;
    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
            a++;
        else if (curr->data == 1)
            b++;
        else
            c++;

        curr = curr->next;
    }
    curr = head;
    while (a or b or c)
    {
        if (a)
        {
            curr->data = 0;
            curr = curr->next;
            --a;
        }

        if (!a and b)
        {
            curr->data = 1;
            curr = curr->next;
            --b;
        }

        if (!a and !b and c)
        {
            curr->data = 2;
            curr = curr->next;
            --c;
        }
    }
    curr = NULL;
    return head;
}

*/

