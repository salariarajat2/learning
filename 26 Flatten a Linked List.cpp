#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n * m), Space Complexity: O(1)

Node *merge(Node *a, Node *b)
{
	Node *result;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	if (a->data < b->data)

		result = a;
	result->bottom = merge(a->bottom, b);
}
else
{
	result = b;
	result->bottom = merge(a, b->bottom);
}
result->next = NULL;
return result;
}
Node *flatten(Node *root)
{
	if (!root or !root->next)
		return root;

	return merge(root, flatten(root->next));
}




/*
//using priority queue
//Time Complexity: O(n * m (log n)), Space Complexity: O(n * m)

struct compare
{
	bool operator()(Node *a, Node *b)
	{
		return a->data >= b->data;
	}
};
Node *flatten(Node *root)
{
	priority_queue<Node *, vector<Node *>, compare> q;

	Node *curr = root;
	while (curr != NULL)
	{
		q.push(curr);
		curr = curr->next;
	}
	Node *head = NULL, *last;
	while (!q.empty())
	{
		Node *top = q.top();
		q.pop();

		if (top->bottom != NULL)
			q.push(top->bottom);

		if (head == NULL)
		{
			head = top;
			last = top;
		}
		else
		{
			last->bottom = top;
			last = top;
		}
	}
	return head;
}
*/




