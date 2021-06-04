#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string g,b;
	cin>>b;
	cin>>g;

	map<char,int> mp;
	for(auto x:g)
		mp[x]++;
	int ans = n;
	for(int i=0;i<n;i++)
	{
		char bride = b[i];
		if(mp[bride] > 0)
		{
			mp[bride]--;
			ans--;
		}
		else
			break;
	}
	cout<<ans<<endl;
}