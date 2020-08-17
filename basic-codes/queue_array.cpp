#include<stdio.h>
#include<iostream>
using namespace std;
#define siz 4
int front = -1,rear = -1;

void insert(int *q)
{
	if((rear+1)%siz == front)
		cout<<"queue is full"<<endl;
	else
	{
		rear = (rear+1)%siz;
		cout<<"enter element: ";
		int element;
		cin>>element;
		q[rear] = element;
	}
}
void delet(int *q)
{
	if(rear==-1)	
		cout<<"queue is empty"<<endl;
	else
	{
		cout<< "deleted : "<<q[front]<<endl;
		if(front==rear)  // if 1 element remaining.
			front=rear=-1;
		else			// if >= 2 element => no problem,just delte.
			front = (front+1)&siz;

	}
}

void display(int *q)
{
	
	if(rear == -1)
		cout<<"queue is empty"<<endl;
	else
	{
		int f = front,r = rear;			// make temp. vars to update.
		while(1)
		{
			cout<<q[f]<<" ";
			f++;
			if(f == r+1)	break;	//all element printed.

			if(f==siz)		f=0; 	// front reaches end but all elem not printed.
		}
		cout<<endl;
	}
}
int main()
{
	int q[siz];
	//int front = -1,rear = -1;
	char ch;
	do
	{
		int op;
		cout<<"operation 1-insert, 2-delete, 3-display: ";
		cin>>op;


		switch(op)
		{
			case 1: insert(q);break;
			case 2: delet(q);break;
			case 3: display(q);break;
			default: cout<<"wrong choice"<<endl;
		}
		cout<<"continue y/n: ";
		getchar();	
		cin>>ch;
	}while(ch!='n');


}
