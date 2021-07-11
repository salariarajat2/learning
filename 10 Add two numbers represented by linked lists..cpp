#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

struct Node *buildList(int size)
{
	int val;
	cin >> val;

	Node *head = new Node(val);
	Node *tail = head;

	for (int i = 0; i < size - 1; i++)
	{
		cin >> val;
		tail->next = new Node(val);
		tail = tail->next;
	}

	return head;
}

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
struct Node *addTwoLists(struct Node *first, struct Node *second)
{

	first = reverse(first);
	second = reverse(second);

	int c = 0, s = 0;
	Node *temp, *res = NULL, *cur = NULL;

	while (first or second)
	{
		s = c + (first ? first->data : 0) + (second ? second->data : 0);
		c = (s >= 10) ? 1 : 0;
		s = s % 10;

		temp = new Node(s);
		if (res == NULL)
			res = temp;
		else
			cur->next = temp;
		cur = temp;
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}

	if (c > 0)
	{
		temp = new Node(c);
		cur->next = temp;
		cur = temp;
	}
	res = reverse(res);
	return res;
}

void printList(Node *n)
{
	while (n)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;

		cin >> n;
		Node *first = buildList(n);

		cin >> m;
		Node *second = buildList(m);

		Node *res = addTwoLists(first, second);
		printList(res);
	}
	return 0;
}

/*
1
2 4 5
3 3 4 5


ans= 3 9 0
*/
