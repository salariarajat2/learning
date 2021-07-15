#include <bits/stdc++.h>
using namespace std;

//Using difference of node counts
//Time Complexity: O(m+n), Auxiliary Space: O(1)

struct Node
{
	int data;
	Node *next;
};

int intersectPoint(Node *head1, Node *head2)
{
	Node *ptr1 = head1;
	Node *ptr2 = head2;
	int c1 = 0, c2 = 0;
	while (ptr1 or ptr2)
	{
		if (ptr1)
		{
			c1++;
			ptr1 = ptr1->next;
		}

		if (ptr2)
		{
			c2++;
			ptr2 = ptr2->next;
		}
	}
	ptr1 = head1, ptr2 = head2;
	int diff = abs(c1 - c2);
	if (c1 > c2)
	{
		while (diff--)
			ptr1 = ptr1->next;
	}
	if (c1 < c2)
	{
		while (diff--)
			ptr2 = ptr2->next;
	}

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if (ptr1) return ptr1->data;
	
	else return -1;
}

void print(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
    Node* newNode;
    Node* head1 = new Node();
    head1->data = 10;

    Node* head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;
     
    print(head1); cout<<endl; print(head2); cout<<endl; 
    cout << "The node of intersection is " << intersectPoint(head1, head2);
}


/*
// two pointer approach
int intersectPoint(Node *head1, Node *head2)
{
	Node *a=head1,*b=head2;
	if(a==NULL or b==NULL) return -1;
	
	while(a!=b)
	{
		a=a->next;
		b=b->next;
		if(a==b) return a->data;
		
		if(a==NULL) a=head2;
		
		if(b==NULL) b=head1;
	}
	
	return a->data;
}

*/
