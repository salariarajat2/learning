#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n*log k),   Auxiliary Space: O(k)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct compare
{
	bool operator()(Node *p1, Node *p2)
	{
		return p1->data > p2->data;
	}
};

struct Node *sortAKSortedDLL(struct Node *head, int k)
{
	if (head == NULL)
		return head;

	priority_queue<Node *, vector<Node *>, compare> pq;
	Node *newHead = NULL, *curr;
	for (int i = 0; head != NULL && i <= k; i++)
	{
		pq.push(head);
		head = head->next;
	}

	while (!pq.empty())
	{
		if (newHead == NULL)
		{
			newHead = pq.top();
			newHead->prev = NULL;
			curr = newHead;
		}

		else
		{
			curr->next = pq.top();
			pq.top()->prev = curr;
			curr = pq.top();
		}
		pq.pop();
		if (head != NULL)
		{
			pq.push(head);
			head = head->next;
		}
	}
	curr->next = NULL;
	return newHead;
}

void push(Node **head, int key)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = key;
	temp->prev = temp->next = NULL;
	if (!*head)
		*head = temp;
	else
	{
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void printList(struct Node *head)
{
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	Node *head = NULL;
	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;
	cout << "Original Doubly linked list:\n";
	printList(head);
	head = sortAKSortedDLL(head, k);
	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}







/*
//insertion sort
Time Complexity: O(n*k), Auxiliary Space: O(1)


struct Node *sortAKSortedDLL(struct Node *head, int k)
{
	if (head == NULL || head->next == NULL)
		return head;

	for (Node *i = head->next; i != NULL; i = i->next)
	{
		Node *j = i;
		while (j->prev != NULL && j->data < j->prev->data)
		{
			Node *temp = j->prev->prev;
			Node *temp2 = j->prev;
			Node *temp3 = j->next;
			j->prev->next = temp3;
			j->prev->prev = j;
			j->prev = temp;
			j->next = temp2;
			if (temp != NULL)
				temp->next = j;
			if (temp3 != NULL)
				temp3->prev = temp2;
		}
		if (j->prev == NULL)
			head = j;
	}
	return head;
}
*/


