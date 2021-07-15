#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(m+n), Auxiliary Space: O(max(m, n))

struct Node
{
	int data;
	Node *next;
};

void push(struct Node **head_ref, int key)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = key;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

struct Node *sortedIntersect(Node *a, Node *b)
{
	if (a == NULL || b == NULL)
		return NULL;

	if (a->data < b->data)
		return sortedIntersect(a->next, b);

	if (a->data > b->data)
		return sortedIntersect(a, b->next);

	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = a->data;

	temp->next = sortedIntersect(a->next, b->next);
	return temp;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{

	Node *a = NULL;
	Node *b = NULL;
	Node *intersect = NULL;
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedIntersect(a, b);
	printList(intersect);
}

/*

Node *sortedIntersect(Node *a, Node *b)
{
	Node *result = NULL;
	Node **lastPtrRef = &result;

	while (a != NULL && b != NULL)
	{
		if (a->data == b->data)
		{
			push(lastPtrRef, a->data);
			lastPtrRef = &((*lastPtrRef)->next);
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
			a = a->next; 
		else
			b = b->next;
	}
	return (result);
}

*/

/*
//Time Complexity: O(m+n), Auxiliary Space: O(min(m, n))

Node* findIntersection(Node *head1, Node *head2)
{
	Node *ptr1 = head1;
	Node *ptr2 = head2;
	Node *head = NULL, *curr;
	while (ptr1 and ptr2)
	{
		if (ptr1->data == ptr2->data)
		{
			if (head == NULL)
			{
				Node *temp = new Node(ptr1->data);
				head = temp;
				curr = temp;
			}
			else
			{
				Node *temp = new Node(ptr1->data);
				curr->next = temp;
				curr = curr->next;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else
		{

			if (ptr1->data > ptr2->data)
				ptr2 = ptr2->next;
			else
				ptr1 = ptr1->next;
		}
	}
	return head;
}
*/
