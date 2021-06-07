#include<bits/stdc++.h>
using namespace std;
int minVans(int n,vector<int> &c,vector<int> &w)
{
	int vtot=0,vsent=0;
	for(int i=0;i<n;i++)
		vtot += w[i];
	if(vtot==0)	return 0;
	sort(c.begin(),c.end());
	int ans;
	for(int i=0;i<n;i++)
	{
		vsent += c[i];
		if(vsent >= vtot)
		{
			ans = i+1;
			break;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int> w(n),c(n);
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		cin>>w[i];

	cout<<minVans(n,c,w);

}