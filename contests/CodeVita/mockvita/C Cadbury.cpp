#include<bits/stdc++.h>
using namespace std;
int Min(int a,int b)
{
	return (a<b?a:b);
}
int calc(int l,int b)
{
	int nl,nb,ans = 0;
	do
	{
		nl = abs(l-b);
		nb = Min(l,b);
		ans++;
		l = nl;	b = nb;
	}while(nl!=0);
	return ans;
}
int main()
{
	int p,q,r,s;
	cin>>p>>q>>r>>s;
	int ans = 0;
	for(int i=p;i<=q;i++)
	{
		for(int j=r;j<=s;j++)
		{
			ans += calc(i,j);
		}
	}
	cout<<ans<<endl;
}