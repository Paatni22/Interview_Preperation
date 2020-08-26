/*
Write a program to add two polynomial and print the resulting polynomial
by using Linked List.
*/

#include<iostream>
using namespace std;
typedef struct term
{
	int coef;
	int degree;
	term *next;
	term(int coef,int degree)
	{
		this->coef = coef;
		this->degree = degree;
		this->next = NULL;
	};
} term;

term * inputPoly(int n)
{
	term *poly = NULL, *rear=NULL;
	int coef,degree;
	for(int i=0;i<n;i++)
	{
		cout<<"enter coefficient: "; 
		cin>> coef;
		cout<<"enter degree		:";
		cin>>degree;
		term *newterm = new term(coef,degree);
		if(poly == NULL)
		{
			poly = newterm;
			rear = newterm;
		}
		else
		{
			rear->next = newterm;
			rear = rear->next;
		}
	}
	return poly;
}
void printPolynomial(term* poly)
{
	while(poly && poly->next)
	{
		cout<<poly->coef<<"x"<<"^"<<poly->degree<<" + ";
		poly = poly->next;
	}
	if(poly && poly->degree!=0)
		cout<<poly->coef<<"x"<<"^"<<poly->degree<<endl;
	else if(poly && poly->degree==0)
		cout<<poly->coef<<endl;
	
}
int main()
{
	int n;
	cout<<"Enter polynomials (in high to low degree order): "<<endl<<endl;
	cout<<"no. of terms in 1st polynomial: ";
	cin>>n;
	term *polya = inputPoly(n);
	cout<<"no. of terms in 2nd polynomial: ";
	cin>>n;
	term *polyb = inputPoly(n);


	printPolynomial(polya);
	printPolynomial(polyb);

	// now start doing sum of polynomials.
	term *sumPoly = NULL,*rear = NULL;
	while(polya && polyb)
	{
		// first we make the new node of sumPoly
		term *nw;
		if(polya->degree == polyb->degree)
		{
			nw = new term(polya->coef + polyb->coef, polya->degree);
			polya = polya->next; polyb = polyb->next;
		}
		else if(polya->degree > polyb->degree)
		{
			nw = new term(polya->coef, polya->degree);
			polya = polya->next;
		}
		else 
		{
			nw = new term(polyb->coef, polyb->degree);
			polyb = polyb->next;
		}

		// now we insert nw node in sumPoly.
		if(sumPoly == NULL)
		{
			sumPoly = rear = nw;
		}
		else
		{
			rear->next = nw;
			rear = rear->next;
		}

	}
	if(polya)
		rear->next = polya;
	if(polyb)
		rear->next = polyb;

	cout<<"sum polynomial: ";
	printPolynomial(sumPoly);
	


}
/*
surajpatni@s:~/Documents/Interview_Preperation/random questions$ g++ add_two_polynomial.cpp 
surajpatni@s:~/Documents/Interview_Preperation/random questions$ ./a.out
Enter polynomials (in high to low degree order): 

no. of terms in 1st polynomial: 3
enter coefficient: 2
enter degree		:4
enter coefficient: 5
enter degree		:1
enter coefficient: 3
enter degree		:0
no. of terms in 2nd polynomial: 4
enter coefficient: 3
enter degree		:100
enter coefficient: 4
enter degree		:5
enter coefficient: 2
enter degree		:3
enter coefficient: 13
enter degree		:0
2x^4 + 5x^1 + 3
3x^100 + 4x^5 + 2x^3 + 13
sum polynomial: 3x^100 + 4x^5 + 2x^4 + 2x^3 + 5x^1 + 16

*/