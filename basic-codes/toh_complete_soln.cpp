#include<bits/stdc++.h>
 
using namespace std;

map<char,stack<int> > mp;

void printStack(stack<int> st)
{
	if(!st.empty())
	{
		int temp = st.top();
		st.pop();
		printStack(st);
		cout<<temp<<" ";
	}
}
void printAll()
{
	cout<<"rod A: [";
	printStack(mp['A']);
	cout<<"], rod B: [";
	printStack(mp['B']);
	cout<<"], rod C: [";
	printStack(mp['C']);
	cout<<"]"<<endl<<endl;
}
int operation = 1;
void toh(char source, char target, char aux, int n)
{
	if(n==1)
	{
		printAll();

		cout<<"op "<<operation++<<"\ttransfer plate no: "<<n<<" from rod : "<<source<<" to "<<target<<endl;
		mp[target].push( mp[source].top()); mp[source].pop();
		
		return;
	}
	toh(source,aux,target,n-1);

	printAll();

	cout<<"op "<<operation++<<"\ttransfer plate no: "<<n<<" from rod : "<<source<<" to "<<target<<endl;
	
	mp[target].push( mp[source].top()); mp[source].pop();

	toh(aux,target,source,n-1);

}
int main()
{
	int n;
	cout<<"enter the no. of rods: ";
	cin>>n;
	for(int i=n;i>0;i--)
		mp['A'].push(i);
	toh('A','C','B',n);
	printAll();
}