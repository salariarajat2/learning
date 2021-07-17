#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

struct Node
{
	int data;
	struct Node *next;
};

bool isCircular(Node *head)
{
	Node *temp=head;
	while (temp != NULL)
	{
		temp = temp->next;
		if (temp == head)
			return true;
	}
	return false;
}

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main()
{
	struct Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	head->next->next->next->next = head;

	isCircular(head) ? cout << "Yes\n" : cout << "No\n";

	return 0;
}


/*
bool isCircular(struct Node *head)
{
	if (head == NULL)
		return true;

	Node *node = head->next;

	while (node != NULL && node != head)
		node = node->next;

	return (node == head);
}
*/


/*
struct Node
{
	int data;
	Node *next;
};

bool check(Node *head)
{
	Node *temp;
	while (temp != NULL)
	{
		temp = temp->next;
		if (temp == head)
		{
			return true;
		}
	}
	return false;
}

void push(Node **head, int key)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = key;
	temp->next = *head;
	*head = temp;
}

void print(Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	Node *a=NULL;
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);
//	a->next->next->next->next = a; 
	check(a) ? cout << "1" : cout << "0";
}

*/

