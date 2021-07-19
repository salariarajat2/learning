#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n^2), Space Complexity: O(1)

struct Node
{
	int data;
	struct Node *next, *prev;
};

int countPairs(struct Node *first, struct Node *second, int value)
{
	int count = 0;
	while (first != NULL && second != NULL && first != second && second->next != first)
	{
		if ((first->data + second->data) == value)
		{
			count++;
			first = first->next;
			second = second->prev;
		}
		else
		{
			((first->data + second->data) > value) ? second = second->prev : first = first->next;
		}
	}
	return count;
}
int countTriplets(struct Node *head, int x)
{
	if (head == NULL)
		return 0;

	Node *current, *first, *last;
	int count = 0;
	last = head;
	while (last->next != NULL)
		last = last->next;

	for (current = head; current; current = current->next)
	{
		first = current->next;
		count += countPairs(first, last, x - current->data);
	}

	return count;
}

void push(Node **head, int key)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = key;
	temp->prev = temp->next = NULL;
	if (!*head)
		*head = temp;
	else
	{
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp;
	}
}

int main()
{
	Node *head = NULL;
	push(&head, 9);
	push(&head, 8);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 2);
	push(&head, 1);

	int x = 17;
	cout << countTriplets(head, x);

	return 0;
}





/*
//hashing
////Time Complexity: O(n^2), Space Complexity: O(n)

int countTriplets(struct Node *head, int x)
{
	struct Node *ptr, *ptr1, *ptr2;
	int count = 0;
	unordered_map<int, Node *> mp;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
		mp[ptr->data] = ptr;

	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
	{
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
		{
			int p_sum = ptr1->data + ptr2->data;
			if (mp.find(x - p_sum) != mp.end() && mp[x - p_sum] != ptr1 && mp[x - p_sum] != ptr2)
			{
				cout << ptr1->data << "  " << ptr2->data << "  " << (x - p_sum) << endl;
				count++;
			}
		}
	}
	return (count / 3);// required count of triplets division by 3 as each triplet is counted 3 times
}
*/




/*
//three for loops
//Time Complexity: O(n^3), Space Complexity: O(1)
int countTriplets(struct Node *head, int x)
{
	struct Node *ptr1, *ptr2, *ptr3;
	int count = 0;

	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
	{
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
		{
			for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
			{

				if ((ptr1->data + ptr2->data + ptr3->data) == x)
				{
					cout << ptr1->data << "  " << ptr2->data << "  " << ptr3->data << endl;
					count++;
				}
			}
		}
	}
	return count;
}
*/


