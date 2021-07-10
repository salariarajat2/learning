#include <bits/stdc++.h>
using namespace std;

// Floyd’s Cycle-Finding Algorithm
// Time Complexity: O(N), Auxiliary Space: O(1)

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
	 Node* a=head,*b=head;
        while(a and b and b->next)
        {
        	
        	a=a->next;
        	b= b->next->next;
        	if(a==b) return 1;
		}
		return 0;
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
	ll.head->next->next->next->next->next = ll.head->next->next;

	if (ll.detectLoop(ll.head))
		cout << "Loop found";
	else
		cout << "No Loop";
	return 0;
}

/*
struct Node
{
	int key;
	struct Node *next;
};

Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

int detectLoop(Node *head)
{
	Node *slow_p = head, *fast_p = head;
	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;//jump by one step
		fast_p = fast_p->next->next;//jump by two step
		if (slow_p == fast_p)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);


	head->next->next->next->next->next = head->next->next;

	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	return 0;
}
*/








/*
// Time Complexity: O(N), Auxiliary Space: O(1)

bool detectLoop(Node *head)
{
	if (!head)
		return false;
	else
	{
		while (head)
		{
			if (head->data == -1)
			{
				return true;
			}
			else
			{
				head->data = -1;
				head = head->next;
			}
		}
		return false;
	}
}


*/





/*
//Hashing Approach
// Time Complexity: O(N), Auxiliary Space: O(N)

bool detectLoop(Node *h)
{
	unordered_set<Node *> s;
	while (h != NULL)
	{

		if (s.find(h) != s.end())
			return true;

		s.insert(h);

		h = h->next;
	}

	return false;
}

//using unordered set
bool detectLoop(Node *head)
{
	if (!head)
		return 0;
	else
	{
		while (head)
		{
			if (head->key == -1)
			{
				return true;
			}
			else
			{
				head->key = -1;
				head = head->next;
			}
		}
		return 0;
	}
}
*/
