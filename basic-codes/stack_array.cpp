#include<iostream>
#define MAX 4
using namespace std;
//int top = -1;

void push(int *stack,int *tp)
{
	if(*tp == MAX-1)
	{	cout<<"full"<<endl;return;}
	else
	{
		int element;
		cout<<"enter the value : ";
		cin>>element;
		stack[++(*tp)] = element;
	}
}
void pop(int stack[],int *tp)
{
	if(*tp == -1)
	{	cout<<"empty stack"<<endl;return;}
	else
	{
		cout<<"popped: "<<stack[*tp]<<endl;
		(*tp)--;
	}
}
void display(int stack[],int top)
{
	for(int i=top;i>=0;i--)
		cout<<stack[i]<<" ";
	cout<<endl;
}
int main()
{
	int stack[MAX];
	int top = -1;
	char ch;
	int op;
	do
	{
		cout<<"1 push, 2 pop, 3 display: "<<endl;
		cin>>op;
		switch(op)
		{
			case 1: push(stack,&top); break;
			case 2: pop(stack,&top); break;
			case 3: display(stack,top); break;
			default: cout<<"wrong i/p"<<endl;

		}
		cout<<"continue :";
		cin>>ch;
	}while(ch!='n');
}