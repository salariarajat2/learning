#include <bits/stdc++.h>
using namespace std;

// TC= O(N), SC=O(1)

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

void reverse(Node **head)
{
	struct Node *temp = NULL;
	struct Node *current = *head;
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
		*head = temp->prev;
}

void push(Node **head, int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->prev = NULL;	  //since we are adding at the beginning,prev is always NULL
	temp->next = (*head); /* link the old list off the new node */
	if ((*head) != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

void print(Node *head)
{
	while (head)
	{
		cout << head->data << "  ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	cout << "Original Linked list ";
	print(head);
	reverse(&head);
	cout << "Reversed Linked list ";
	print(head);
}


/*
// using stacks
// TC= O(N), SC=O(N)
void reverse()
{
	stack<int> st;
	Node *temp = head;
	while (temp != NULL)
	{
		st.push(temp->data);
		temp = temp->next;
	}

	temp = head;
	while (temp != NULL)
	{
		temp->data = st.top();
		st.pop();
		temp = temp->next;
	}
}
*/
