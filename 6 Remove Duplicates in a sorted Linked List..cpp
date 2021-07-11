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

	Node* check(Node *head)
	{
		Node *root = head;
		while(root->next != NULL)
		{
			if(root->data == root->next->data)
			{
				root->next= root->next->next;
			}
			else{
				root = root->next;
			}
		}
		return head;
	}

	Node push(int data)
	{
		Node *temp = new Node(data);
		temp->next = head;
		head = temp;
	}

	void print()
	{
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

int main()
{
	linked ll;
	ll.push(11);
	ll.push(11);
	ll.push(11);
	ll.push(13);
	ll.push(13);
	ll.push(20);

     ll.print();
	 cout<<endl;
	 ll.check(ll.head);
	 ll.print();


	return 0;
}

/*
Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node *p=root,*q;
 while(p!=NULL){
    while(p->next && p->data==p->next->data){
        q=p->next;
        p->next=q->next;
        q->next=NULL;
        delete q;
        
    }
    p=p->next;
 }
 return root;
}
*/




/*
//Recursion

void removeDuplicates(Node *head)
{
	Node *to_free;
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		if (head->data == head->next->data)
		{
			to_free = head->next;
			head->next = head->next->next;
			free(to_free);
			removeDuplicates(head);
		}
		else
		{
			removeDuplicates(head->next);
		}
	}
}
*/
