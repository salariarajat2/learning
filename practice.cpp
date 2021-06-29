#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *right,*left;
};
int ma=INT_MIN;
int m(Node *root)
{
	if(!root) return 1;
	int x=m(root->left);
	int y=m(root->right);
	ma=max(ma,x+y+1);
	return (max(x,y)+1);
	
}

Node *newNode(int key)
{
	Node *temp=new Node;
	temp->data=key;
	temp->right = temp->left = NULL;
	return temp;
}

int main()
{
	
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Diameter of the given binary tree is " << m(root);
    return 0;
	
}


