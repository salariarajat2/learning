#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

struct Node
{
	int data;
	Node *next;
};

void splitList(Node *head1, Node **a, Node **b)
{
	Node *slow = head1;
	Node *fast = head1->next;

	while (fast != head1 and fast->next != head1)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	*a = head1;
	*b = slow->next;
	slow->next = *a;
	Node *aa = (*b);
	while (aa->next != head1)
	{
		aa = aa->next;
	}
	aa->next = (*b);
}

void push(Node **head, int data)
{
	Node *ptr1 = new Node();
	Node *temp = *head;
	ptr1->data = data;
	ptr1->next = *head;

	if (*head != NULL)
	{
		while (temp->next != *head)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head = ptr1;
}

void print(Node *head)
{
	Node *temp = head;
	if (head != NULL)
	{
		cout << endl;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}
}

int main()
{
	Node *head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;

	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);

	cout << "Original Circular Linked List   ";
	print(head);

	splitList(head, &head1, &head2);

	cout << "\nFirst Circular Linked List";
	print(head1);

	cout << "\nSecond Circular Linked List";
	print(head2);
	return 0;
}

