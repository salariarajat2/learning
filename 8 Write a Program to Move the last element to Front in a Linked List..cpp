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
	
void moveToFront(Node **head_ref) 
{ 
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
  
    Node *secLast = NULL; 
    Node *last = *head_ref; 
  
    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
  
    secLast->next = NULL; 
    last->next = *head_ref; 
    *head_ref = last; 
} 

	Node push(int data)
	{
		Node *temp = new Node(data);
		temp->next = head;
		head = temp;
	}

	void print(Node *head)
	{
		while (head)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}
};

int main()
{
	linked ll;
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);

	ll.print(ll.head);
	cout << endl;
	ll.moveToFront(&(ll.head));
	ll.print(ll.head);

	return 0;
}

