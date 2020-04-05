#include<iostream>
#include<climits>
#include<math.h>
#define MOD pow(10,9)+7

using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int ans = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int p=1,max=0;
		for(int j=0;j<m;j++)
		{
			int curr;
			cin>>curr;
			if(curr>1)	p = (p * curr) % MOD;
			if(max<curr)	max = curr;

		}
		if(p==1)	p = max;
		if(ans<p)	ans = p;
	}
	cout<<ans<<endl;
}