#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(vn), Space Complexity: O(1)

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

	Node *check(Node *head)
	{
		Node *high = head, *low = head;
		while (low and high and high->next)
		{
			low = low->next;
			high = high->next->next;
			if (low == high)
				break;
		}

		if (low != high)
			return NULL;

		low = head;
		while (low != high)
		{
			high = high->next;
			low = low->next;
		}
		return low;
	}

	Node push(int data)
	{
		Node *temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	linked ll;
	ll.push(10);
	ll.push(4);
	ll.push(15);
	ll.push(20);
	ll.push(50);

	ll.head->next->next->next->next->next = ll.head->next->next;
	cout << "loop found at element having data " << (ll.check(ll.head))->data;

	return 0;
}
