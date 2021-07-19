#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

struct Node
{
	int data;
	Node *next, *prev;
};

void push(Node **head, int key)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = key;
	temp->next = temp->prev = NULL;
	if ((*head))
	{
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp;
	}
	else
	{
		(*head) = temp;
	}
}

Node *rotate(Node *head, int k)
{
	if (!head)
		return NULL;
	head->prev = NULL;
	Node *curr = head, *newHead;
	int count = 0;
	while (curr != NULL && count < k)
	{
		newHead = curr;
		swap(curr->next,curr->prev);
		curr = curr->prev;
		count++;
	}

	if (count >= k)
	{
		head->next = rotate(curr, k);
	}
	return newHead;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	Node *head = NULL;
	for (int i = 11; i >= 1; i--)
	{
		push(&head, i);
	}
	int k = 3;
	cout << "Original list: ";
	printList(head);
	head = rotate(head, k);

	cout << "\nModified list: ";
	printList(head);
	return 0;
}




/*

Node *getNode(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

void push(Node **head, Node *temp)
{

	temp->prev = NULL;
	temp->next = (*head);
	if ((*head) != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

Node *rotate(Node *head, int k)
{
	Node *current = head;
	Node *next = NULL;
	Node *newHead = NULL;
	int count = 0;

	while (current && count < k)
	{
		next = current->next;
		push(&newHead, current);
		current = next;
		count++;
	}

	if (next != NULL)
	{
		head->next = rotate(next, k);
		head->next->prev = head;
	}

	return newHead;
}
*/
