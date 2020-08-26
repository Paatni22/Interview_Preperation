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
		(*hd)->next = nw;
	}
	else if((*hd)->next == NULL)
	{
		(*hd)->next = nw;
		nw->next = *hd;
	}
	else
	{
		nw->next = (*hd)->next;
		(*hd)->next = nw;
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
		if((*hd)->next == *hd)	//only 1 element present.
			*hd = NULL;
		else			//more than 1 element.
		{
			//I copy next node data to head node
			// and delete next node
			// to make deletion O(1) instead of O(n)
			(*hd)->data = (*hd)->next->data;
			temp = (*hd )->next;
			(*hd)->next = (*hd)->next->next;

		}
		cout<<"deleted element: "<<element<<endl;
		delete temp;
	}
	else if((*hd))// other than first elem to be deleted.
	{
		node *t = *hd;
		while(t->next!=*hd && t->next->data!=element)
		{
			t = t->next;
		}
		if(t->next == *hd)		// if we reach to the last node and elem not present.
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
	cout<<"circ. linked list is : ";
	if(!head){ 
		cout<<"empty LL"<<endl;return;
	}

	node *t = head;
	while(t->next != head)
	{
		cout<<t->data<<" -> ";
		t = t->next;
	}
	cout<<t->data<<endl;
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