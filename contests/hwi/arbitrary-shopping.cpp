// for question refer to the pdf in the same directory.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int max(int a,int b){	return (a>b?a:b);}
int maxOutfits(vector<int> &v,int money)
{
	int n = v.size();
	int sum=0;
	queue<int> q;
	int maxLen=0;
	for(int i=0;i<n;i++)
	{
		if(sum+v[i] > money)
		{
			if(v[i] > money)	continue;
			while(sum+v[i] >money)
			{
				sum -= q.front();
				q.pop();
			}
		}
		q.push(v[i]);
		sum += v[i];
		maxLen = max(maxLen, q.size());

	}
	return maxLen;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &x:v)
		cin>>x;
	int money;
	cin>>money;

	cout<<maxOutfits(v,money);
}