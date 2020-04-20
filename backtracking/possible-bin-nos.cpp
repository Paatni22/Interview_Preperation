/* 
Q. to generate all n bit binary no.s with m ones.
test case:
 if n = 3, m = 1;
 ans : 
 100
 010
 001
 
*/

#include<bits/stdc++.h>
using namespace std;
void poss(vector<int> &dw,int i,int n)
{
	if(n==0)
	{
		for(auto x:dw)
			cout<< x;
		cout<<endl;	return;
	}
	if(i==-1)	return;	// or cond. can be: if(i+1 < n) 

	poss(dw,i-1,n);
	dw[i] = 1;
	poss(dw,i-1,n-1);
	dw[i] = 0;
}
int main()
{
	int n,m; 
	cout<<"bits: ";cin>>n;
	cout<<"ones: ";cin>>m;

	vector<int> dw(n,0);
	poss(dw,n-1,m); // 10

}