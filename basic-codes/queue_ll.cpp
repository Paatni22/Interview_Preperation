#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
	int data;
	node *next;
} node;

void insert(node **ft,node **rr)    // to pass pointers by address, have to use double pointers.
{
	node *nw = (node*)malloc(sizeof(node));
	if(nw==NULL)
		cout<<"memory error"<<endl;
	else
	{
		cout<<"enter element: ";
		int element;
		cin>>element;
		nw->data = element;
		nw->next = NULL;
		if((*ft)==NULL)
		{
			(*ft) = (*rr) = nw;
		}
		else 
		{
			(*rr)->next = nw;
			(*rr) = nw;
		}
	}
}
void delet(node **ft,node **rr)
{
	if(*ft==NULL)
		cout<<"queue is empty"<<endl;
	else
	{
		node * temp = (*ft);
		(*ft) = (*ft)->next;
		if((*ft)==NULL)		*rr = NULL;

		delete(temp);
	}
}
void display(node *front,node *rear)
{
	if(front==NULL)
		cout<<"queue is empty"<<endl;
	else
	{
		while(front)
		{
			cout<<front->data<<" ";
			front = front->next;
		}
	}
}
int main()
{
	node *front=NULL,*rear = NULL;

	char ch;
	do
	{
		int op;
		cout<<"operation 1-insert, 2-delete, 3-display: ";
		cin>>op;


		switch(op)
		{
			case 1: insert(&front,&rear);break;
			case 2: delet(&front,&rear);break;
			case 3: display(front,rear);break;
			default: cout<<"wrong choice"<<endl;
		}
		cout<<"continue y/n: ";
		
		cin>>ch;
	}while(ch!='n');

}
