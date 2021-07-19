#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

struct Node
{
	int data;
	struct Node *next, *prev;
};

void pairSum(Node *head, int x)
{
	Node *start = head, *end = head;
	bool f = false;
	while (end->next)
	{
		end = end->next;
	}
	
	while (start != end and start != end->next) // The loop terminates when two pointers cross each other (second->next == first), or they become same (first == second)
	{
		if ((start->data + end->data) == x)
		{
			f = true;
			cout << start->data << " " << end->data << endl;
			start = start->next;
			end = end->prev;
		}

		else
		{
			((start->data + end->data) > x) ? end = end->prev : start = start->next;
		}
	}
	if (!f)
		cout << "not found";
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

int main()
{
	Node *head = NULL;
	push(&head, 9);
	push(&head, 8);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 2);
	push(&head, 1);
	int x = 7;

	pairSum(head, x);

	return 0;
}




