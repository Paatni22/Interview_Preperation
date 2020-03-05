// for question refer to the pdf in the same directory.

#include<bits/stdc++.h>
using namespace std;
char slowestKeyPress(vector<vector<int> > v)
{
	int maxKey = v[0][0],maxTime = v[0][1];
	int n = v.size();
	for(int i=1;i<n;i++)
	{
		int curr = v[i][1]-v[i-1][1];
		if(curr > maxTime)
		{
			maxTime = curr;
			maxKey = v[i][0];
		}
	}
	return 'a'+ maxKey;
}


int main()
{
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(2));
	for(auto &row : v)
		for(auto &val: row)
			cin>>val;
	cout<< slowestKeyPress(v)<<endl;


}