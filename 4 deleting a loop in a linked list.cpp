#include <bits/stdc++.h>
using namespace std;

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

	int detectLoop(Node *head)
	{
		Node *a = head, *b = head;
		while (a and b and b->next)
		{

			a = a->next;
			b = b->next->next;
			if (a == b)
				return 1;
		}
		return 0;
	}

	Node* removeLoop(Node *head)
	{
		Node *high = head, *low = head;

		while (low and high and high->next)
		{
			low = low->next;
			high = high->next->next;
			if (low == high)
				break;
		}

		if (low == head)
		{
			while (high->next != low)
			{
				high = high->next;
			}
			high->next = NULL;
			return high;
		}
		else if (low == high)
		{
			low = head;
			while (low->next != high->next)
			{
				low = low->next;
				high = high->next;
			}
			high->next = NULL;
			return high;
		}
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
	ll.push(8);
	ll.push(7);
	ll.push(6);
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);
 ll.head->next->next->next->next->next->next->next = ll.head->next;

	if (ll.detectLoop(ll.head))
		cout << "Loop found"<<endl;
	else
		cout << "No Loop"<<endl;

    cout<<"loop found at element having data "<<(ll.removeLoop(ll.head))->data;
   
    
	return 0;
}
