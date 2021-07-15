#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)

struct Node
{
	int data;
	struct Node *next;
};

void printMiddle(Node *head)
{
	int count = 0;
	Node *mid = head;

	while (head)
	{
		if (count & 1) mid = mid->next;
		count++;
		head = head->next;
	}

	if (mid != NULL) cout <<"the mid of the linked list is "<< mid->data;
}
void print(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void push(struct Node **head_ref, int key)
{
	Node *new_Node = (Node *)malloc(sizeof(Node));
	new_Node->data = key;
	new_Node->next = (*head_ref);
	(*head_ref) = new_Node;
}

int main()
{
	int n;
	cin >> n;
	Node *head = NULL;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		push(&head, a);
	}
	print(head);
	cout<<endl;
	printMiddle(head);
	return 0;
}

/*
//Time Complexity: O(n/2), Space Complexity: O(1)

Node *printMiddle(Node *head)
{

	Node *slow = head;
	Node *fast = head;

	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
*/
