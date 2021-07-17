#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

void push(Node **head_ref, int data)
{
	Node *ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = *head_ref;

	if (*head_ref != NULL)
	{
		Node *temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1;

	*head_ref = ptr1;
}

void printList(Node *head)
{
	Node *temp = head;
	if (head != NULL)
	{
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}

	cout << endl;
}

bool deleteNode(Node **head, int key)
{

	if (*head == NULL) // If linked list is empty
		return true;

	if ((*head)->data == key && (*head)->next == *head) // If the list contains only a single node
	{
		free(*head);
		*head = NULL;
		return true;
	}

	Node *last = *head, *d;
	if ((*head)->data == key)// If head is to be deleted
	{
		while (last->next != *head)
			last = last->next;
		last->next = (*head)->next;
		free(*head);
		*head = last->next;
		return true;
	}

	while (last->next != *head)
	{
		if (last->next->data == key)
		{
			d = last->next;
			last->next = d->next;
			free(d);
			return true;
		}
		last = last->next;
	}
	return false;
}

int main()
{
	Node *head = NULL;
	push(&head, 2);
	push(&head, 5);
	push(&head, 7);
	push(&head, 8);
	push(&head, 10);

	cout << "List Before Deletion: ";
	printList(head);

	deleteNode(&head, 2)? cout<<"Deleted successfully"<<endl : cout<<"Not found"<<endl;

	cout << "List After Deletion: ";
	printList(head);

	return 0;
}
