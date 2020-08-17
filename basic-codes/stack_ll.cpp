#include<iostream>
#include<stdlib.h>

using namespace std;
//node* top = NULL;
typedef struct node {
	int data;
	node * next;
} node;

void push(node **tp)
{
	node *nw = (node*)malloc(sizeof(node));
	if(nw == NULL){	cout<<"error"<<endl;return;}
	int element;
	cout<<"enter the value : ";
	cin>>element;
	nw->data = element;
	nw->next = NULL;
	if(*tp == NULL)	*tp = nw;
	else
	{
		nw->next = *tp;
		*tp = nw;
	}

}
void pop(node **tp)
{
	if(*tp == NULL)
	{	cout<<"empty stack"<<endl;return;}
	else
	{
		cout<<"popped: "<<(*tp)->data<<endl;
		node* temp = *tp;
		*tp = (*tp)->next;
		free(temp);
	}
}
void display(node *top)
{
	if(top == NULL)
	{	cout<<"empty stack"<<endl;return;}
	while(top)
	{
		cout<<top->data<<" ";
		top=top->next;
	}
	cout<<endl;
}
int main()
{
	node *top = NULL;
	char ch;
	int op;
	do
	{
		cout<<"1 push, 2 pop, 3 display: "<<endl;
		cin>>op;
		switch(op)
		{
			case 1: push(&top); break;
			case 2: pop(&top); break;
			case 3: display(top); break;
			default: cout<<"wrong i/p"<<endl;

		}
		cout<<"continue :";
		cin>>ch;
	}while(ch!='n');
}