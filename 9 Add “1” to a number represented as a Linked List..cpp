#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(1)
struct Node
{
	int data;
	Node *next;
	Node(int key)
	{
		this->data = key;
		next = NULL;
	}
};

struct linked
{

	Node *head;
	linked() { head = NULL; }

	Node *reverse(Node *head)
	{
		Node *cur = head, *prev = NULL, *next = NULL;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	
	
	Node *addOne(Node *head)
	{
		head = reverse(head);
		bool f = true;
		Node *cur = head;
		while (f == true and cur != NULL)
		{
			if (cur->data == 9 and cur->next == NULL)
			{
				cur->data = 1;
				Node *temp = new Node(0);
				temp->next = head;
				head = temp;
				cur = cur->next;
			}
			else if (cur->data == 9)
			{
				cur->data = 0;
				cur = cur->next;
			}
			else
			{
				cur->data += 1;
				cur = cur->next;
				f = false;
			}
		}

		head = reverse(head);
		return head;
	}

	void print(Node *head)
	{
		while (head)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}

	void *push(int value)
	{
		Node *temp = new Node(value);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	linked ll;
	ll.push(9);
	ll.push(9);
	ll.push(9);

	ll.print(ll.head);
	cout << endl;
	ll.addOne(ll.head);
	ll.print(ll.head);
}





/*
//using Recursion


int addWithCarry(Node *head)
	{
		if (head == NULL)
			return 1;
		int res = head->data + addWithCarry(head->next);
		head->data = (res) % 10;
		return (res) / 10;
	}

	Node *addOne(Node *head)
	{
		int carry = addWithCarry(head);
		if (carry)
		{
			Node *newNode = new Node(carry);
			newNode->next = head;
			return newNode;
		}
		return head;
	}
	*/
