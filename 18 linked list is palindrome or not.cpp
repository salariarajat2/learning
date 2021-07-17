#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

struct Node
{
	int data;
	Node *next;
};

bool isPalindrome(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	Node *prev = NULL, *next, *curr = slow;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	fast = head;

	while (prev)
	{
		if (prev->data != fast->data)
			return false;

		prev = prev->next;
		fast = fast->next;
	}

	return true;
}

void push(Node **head, int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = (*head);
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
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Original Circular Linked List   ";
	print(head);
	cout << endl;
	cout << isPalindrome(head);
	return 0;
}


/*
// using stacks
//Time Complexity: O(n), Space Complexity: O(n)

bool isPalin(Node *head)
{
	Node *first = head;
	stack<int> s;
	while (first)
	{
		s.push(first->data);
		first = first->next;
	}

	while (head)
	{
		int n = s.top();
		s.pop();
		if (head->data != n)
		{
			return false;
		}
		head = head->next;
	}
	return true;
}

*/



/*

// using recursion
//Time Complexity: O(n), Space Complexity: O(n)

bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
    if (right == NULL) 
        return true; 
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false; 
    bool isp1 = (right->data == (*left)->data); 

    *left = (*left)->next; 

    return isp1; 
} 

bool isPalindrome(struct node* head) 
{ 
    isPalindromeUtil(&head, head); 
} 
*/
