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


