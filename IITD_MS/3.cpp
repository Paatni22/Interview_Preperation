#include<bits/stdc++.h>
using namespace std;

void explore(vector<string> &a,vector<vector<int>> &vis,
	int &len,int i,int j)
{
	int m = vis.size(), n = vis[0].size();
	if(i<0 || i>=m || j<0 || j>=n || a[i][j] != 'R' || 
		vis[i][j] == 1)
		return;
	len++; vis[i][j] = 1;
	explore(a,vis,len,i+1,j); explore(a,vis,len,i-1,j);
	explore(a,vis,len,i,j+1); explore(a,vis,len,i,j-1);
	explore(a,vis,len,i+1,j+1); explore(a,vis,len,i+1,j-1);
	explore(a,vis,len,i-1,j+1); explore(a,vis,len,i-1,j-1);
}
int main()
{
	int m,n;
	cin>>m>>n;
	vector<string> a(m);
	for(auto &str: a)
		cin>>str;
	vector<vector<int>> vis(m,vector<int>(n,0));
	int k=0,s=0,b=0;
	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<vis[i][j];
	// 	}
	// 	cout<<endl;
	// }	
	// cout<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int len =0;
			if(a[i][j] == 'R' && vis[i][j]==0)
			{
				k++;
				explore(a,vis,len,i,j);
				if(len >b)
					b = len;
				if(len<s || s==0)
					s = len;
			}
		}
	}
	cout<<k<<" "<<s<<" "<<b<<endl;
	int ans = (s*k +13)%(b*b);
	cout<<"ans = "<<ans;


}