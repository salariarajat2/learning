#include <bits/stdc++.h>
using namespace std;

//using recursion
//Time Complexity: O(n), Auxiliary Space: O(n/k). 

struct Node
{
	int data;
	struct Node *next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList
{
	Node *head;
	LinkedList()
	{
		head = NULL;
	}

	Node* reverse(Node *head,int n)
	{
	    if(!head) return NULL;
		Node *curr=head,*prev=NULL,*next=NULL;
		int count=0;
		while(curr !=NULL and count<n)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			count++;
		 } 
		 
		 if(next!=NULL)
		 {
		 	head->next= reverse(next,n);
		 	
		 }
		 return prev;
	}     

	void print()
	{
		struct Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

		void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(8);
	ll.push(7);
	ll.push(6);
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);

	cout << "Given linked list \n";
	ll.print();
	ll.head = ll.reverse(ll.head, 3);

	cout << "\nReversed Linked list \n";
	ll.print();

	return (0);
}


/*
//using stacks
//Time Complexity: O(n), Auxiliary Space: O(k). 

struct Node* Reverse(struct Node* head, int k)
{
	stack<Node*> mystack;
	struct Node* current = head;
	struct Node* prev = NULL;

	while (current != NULL) {

		int count = 0;
		while (current != NULL && count < k) {
			mystack.push(current);
			current = current->next;
			count++;
		}

		while (mystack.size() > 0) {

			if (prev == NULL) {
				prev = mystack.top();
				head = prev;
				mystack.pop();
			} else {
				prev->next = mystack.top();
				prev = prev->next;
				mystack.pop();
			}
		}
	}

	prev->next = NULL;

	return head;
}
*/
