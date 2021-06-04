#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	node *next,*prev;
	node(int data)
	{
		this->data = data;
		this->prev = this->next = NULL;
	};
} node;
void insert(node **hd)
{
	int element;
	cout<<"enter element to be inserted: ";
	cin>> element;
	node *nw = new node(element);

	if(*hd == NULL)
	{
		*hd = nw;
	}
	else
	{
		(*hd)->prev = nw;
		nw->next = *hd;
		*hd = nw;
	}
}

void delet(node **hd)
{
	if(*hd==NULL){ cout<<"empty LL"<<endl; return;}

	int element;
	cout<<"enter the element to be deleted : ";
	cin>>element;
	node *t = *hd , *temp;
	
	if(t->data == element)	//first node to be deleted.
	{
		temp = t;
		if(t->next)	t->next->prev = NULL;
		*hd = (*hd)->next;
	}
	else
	{
		while(t && t->data != element)
		{
			t = t->next;
		}
		if(t==NULL){	// if element is not present
			cout<<"element not present"<<endl; return;
		}

		//means element present and pointed by t
		temp = t;
		if(t->next == NULL)
			t->prev->next = NULL;
		else
		{
			t->prev->next = t->next;
			t->next->prev = t->prev;
		}

	}
	cout<<"deleted element: "<<temp->data<<endl;
	delete temp;
}
void display(node *head)
{
	if(head==NULL){ cout<<"empty LL"<<endl; return;}
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