/*
Convert a given Binary Tree to Doubly Linked List | Set 3
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL)
 In-Place. The left and right pointers in nodes are to be used as
  previous and next pointers respectively in converted DLL. The 
  order of nodes in DLL must be same as Inorder of the given Binary
   Tree. The first node of Inorder traversal (left most node in BT) 
   must be head node of the DLL.
https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
*/
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *left,*right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
	//node(val): data(val),left(NULL),right(NULL);
}node ;

 /*
 Tree look like this :	

			4
				
	2				6
1		3		5		7


*/
void Inorder(node *root,node** head )
{
	if(root == NULL)	return;

	Inorder(root->left, head);

	if(*head==NULL)	*head = root;

	//manipulation.
	static node *prev = NULL;
	root->left = prev;
	if(prev)	prev->right = root;
	prev = root;
	//

	Inorder(root->right,head);

}
void printDll(node *head)
{
	node *reverseHead = NULL;
	while(head)
	{
		cout<<head->data<<" ";
		reverseHead = head;
		head = head->right;
	}
	cout<<endl;
	while(reverseHead)
	{
		cout<<reverseHead->data<<" ";
		reverseHead = reverseHead->left;
	}
	cout<<endl;
}
int main()
{
	node *root = new node(4);
	root->left = new node(2);
	root->right = new node(6);
	root->left->left = new node(1);
	root->left->right = new node(3);
	root->right->left = new node(5);
	root->right->right = new node(7);

	//node *prev = NULL;
	node * head = NULL;
	Inorder(root,&head);

	printDll(head);

}