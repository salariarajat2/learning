#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void rotate(Node **head, int x)
{
	if (x == 0)
		return;

	Node *curr = (*head), *nh;
	int count = 1; //because curr is intilized with the head
	while (count < x and curr)
	{
		curr = curr->next;
		count++;
	}

	nh = curr;

	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = (*head);
	(*head)->prev = curr;
	(*head) = nh->next;
	(*head)->prev = NULL;
	nh->next = NULL;
}

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

void printList(Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver's Code
int main(void)
{
	Node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	int N = 2;
	cout << "Given linked list \n";
	printList(head);
	rotate(&head, N);
	cout << "\nRotated Linked list \n";
	printList(head);

	return 0;
}

