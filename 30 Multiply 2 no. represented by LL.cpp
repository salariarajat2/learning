#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

class Node
{
public:
    int data;
    Node *next;
};

long long multiplyTwoLists(Node *first, Node *second)
{
    long long a = 0, b = 0, c = 1e9 + 7;
    while (first or second)
    {
        if (first)
        {
            a = ((a)*10) % c + first->data;
            first = first->next;
        }

        if (second)
        {
            b = ((b)*10) % c + second->data;
            second = second->next;
        }
    }

    return ((a) * (b)) % c;
}

void push(Node **head, int key)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->next = (*head);
    (*head) = temp;
}

int main(void)
{
    Node *first = NULL;
    Node *second = NULL;
    push(&first, 2);
    push(&first, 3);
    push(&second, 2);

    cout << multiplyTwoLists(first, second);
    return 0;
}
