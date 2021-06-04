#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
} node;

void insert(node **hd)
{
	cout<<"enter new node value: ";
	int element;
	cin>>element;
	node *nw = new node(element);

	// put this new node in LL.
	if((*hd) == NULL)
	{
		*hd = nw;
	}
	else
	{
		nw->next = *hd;
		*hd = nw;
	}
}

void delet(node **hd)
{
	int element;
	cout<<"enter element to be deleted: ";
	cin>>element;
	node *temp;
	if((*hd) && (*hd)->data == element)  // first elem to delete
	{
		temp = (*hd);
		(*hd) = (*hd)->next;
		cout<<"deleted element: "<<element<<endl;
		delete temp;
	}
	else if((*hd))// other than first elem to be deleted.
	{
		node *t = *hd;
		while(t && t->next && t->next->data!=element)
		{
			t = t->next;
		}
		if(!t->next)		// if we reach to the last node and elem not present.
			cout<<"element not present"<<endl;
		else
		{
			cout<<"deleted element: "<<element<<endl;
			temp = t->next;
			t->next = t->next->next;
			delete temp;
		}
			
	}
	
}
void display(node *head)
{
	cout<<"linked list is : ";
	if(!head) cout<<"empty";
	while(head)
	{
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}
int main()
{
	node *head = NULL;
	int op;char ch;
	do
	{
		cout<< "enter the operation :\n 1-insert,2-delete,3-display: ";
		cin>>op;
		switch(op)
		{
			case 1: insert(&head);break;
			case 2: delet(&head); break;
			case 3: display(head); break;
			default: cout<<"wrong choice"<<endl;
		}
		cout<<"continue y/n: ";
		cin>>ch;

	}while(ch!='n');

}