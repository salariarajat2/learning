#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n*log n), Space Complexity: O(n*log n)

struct Node
{
	int data;
	Node *next;
};

Node *merge(Node *a, Node *b)
{
	Node *answer = NULL;

	if (!a)
		return (b);
	else if (!b)
		return (a);

	if (a->data <= b->data)
	{
		answer = a;
		answer->next = merge(a->next, b);
	}
	else
	{
		answer = b;
		answer->next = merge(a, b->next);
	}
	return (answer);
}

void breaklist(Node *source, Node **first, Node **second)
{

	Node *slow = source;
	Node *fast = source->next;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*first = source;
	*second = slow->next;
	slow->next = NULL;
}

void MergeSort(Node **head)
{
	Node *curr = *head;
	Node *a;
	Node *b;

	if ((!curr) || (!curr->next))
	{
		return;
	}
	breaklist(curr, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = merge(a, b);
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

void push(struct Node **head_ref, int key)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = key;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{

	Node *res = NULL;
	Node *a = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	MergeSort(&a);

	cout << "Sorted Linked List is: \n";
	printList(a);

	return 0;
}

