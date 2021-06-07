#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
	if(n==0)	return 1;
	return n*fact(n-1);
}
int noOfWays(int si,int sj,int fi,int fj)
{
	int Down = fi-si;
	int Right = fj-sj;
	int waysToArrange = fact(Down + Right)/ (fact(Down) * fact(Right));
	return waysToArrange;
}
int main()
{
	int m,n,p,q;
	cin>>m>>n>>p>>q;

	int ways1 = noOfWays(0,0,p,q);
	int ways2 = noOfWays(p,q,m-1,n-1);

	int ans = ways1*ways2;
	cout<<ans;
}