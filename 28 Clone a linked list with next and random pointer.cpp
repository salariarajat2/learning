#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

class Node
{
public:
    int data;
    Node *next, *random;

    Node(int data)
    {
        this->data = data;
        this->next = this->random = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList(Node *head)
    {
        this->head = head;
    }

    void push(int data)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *random = temp->random;
            int randomData = (random != NULL) ? random->data : -1;
            cout << "Data = " << temp->data << ", "
                 << "Random Data = " << randomData << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    LinkedList *clone()
    {
        Node *curr = head;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while (curr)
        {
            curr->next->random = curr->random ? curr->random->next : NULL; //curr->next->arb=curr->arb? curr->arb->next : NULL;
            curr = curr->next->next;
        }
        Node *o = head, *c = head->next;
        curr = c;
        while (o and c)
        {
            o->next = o->next->next;
            c->next = c->next ? c->next->next : NULL;
            o = o->next;
            c = c->next;
        }
        return new LinkedList(curr); // return curr;
    }
};

int main()
{
    LinkedList *ll = new LinkedList(new Node(5));
    ll->push(4);
    ll->push(3);
    ll->push(2);
    ll->push(1);

    ll->head->random = ll->head->next->next;
    ll->head->next->random = ll->head->next->next->next;
    ll->head->next->next->random = ll->head->next->next->next->next;
    ll->head->next->next->next->random = ll->head->next->next->next->next->next;
    ll->head->next->next->next->next->random = ll->head->next;

    LinkedList *clone = ll->clone();
    cout << "Original linked list\n";
    ll->print();
    cout << "\nCloned linked list\n";
    clone->print();
}


/*
//using hashing
//Time Complexity: O(n), Space Complexity: O(1)
LinkedList *clone()
{
    Node *origCurr = head;
    Node *cloneCurr = NULL;
    unordered_map<Node *, Node *> mp;

    while (origCurr != NULL)
    {
        cloneCurr = new Node(origCurr->data);
        mp[origCurr] = cloneCurr;
        origCurr = origCurr->next;
    }

    origCurr = head;

    while (origCurr != NULL)
    {
        cloneCurr = mp[origCurr];
        cloneCurr->next = mp[origCurr->next];
        cloneCurr->random = mp[origCurr->random];
        origCurr = origCurr->next;
    }

    return new LinkedList(mp[head]);
}
*/
