#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n), Space Complexity: O(n)

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

	Node *removeDuplicates(Node *head)
	{
		unordered_map<int, int> mp;
		Node *cur = head;
		mp[cur->data] = 1;
		Node *prev = cur;
		cur = head->next;
		while (cur != NULL)
		{
			if (mp[cur->data])
			{
				prev->next = cur->next;
				free(cur);
			}
			else
			{
				mp[cur->data] = 1;
				prev = cur;
			}
			cur = prev->next;
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
		Node *temp = head;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main()
{
	linked ll;
	ll.push(4);
	ll.push(2);
	ll.push(2);
	ll.push(5);

	ll.print();
	cout << endl;
	ll.removeDuplicates(ll.head);
	ll.print();

	return 0;
}

/*
Node *removeDuplicates(Node *root)
{
    Node *p=root,*q=NULL;
    unordered_set<int>hash;
    
    while(p!=NULL){
        if(hash.find(p->data)==hash.end()){
            hash.insert(p->data);
            q=p;
        }
        else{
            q->next=p->next;
            delete p;
        }
        p=q->next;
    }
    return root;
    
}
*/

/*Brute force, TC=O(n^2)

void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
//     Pick elements one by one 
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
 
//        Compare the picked element with rest of the elements 
        while (ptr2->next != NULL)
        {
//            If duplicate then delete it 
            if (ptr1->data == ptr2->next->data)
            {
//                sequence of steps is important here 
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;//This is tricky 
        }
        ptr1 = ptr1->next;
    }
}
*/
