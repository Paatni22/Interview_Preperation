#include<bits/stdc++.h>
using namespace std;
bool mycomp(const vector<int>& first,const vector<int>& second)
{
	return first[1]<=second[1];
}
int main()
{
	vector<vector<int>> v;
	v.push_back(vector<int>{1,21});
	v.push_back(vector<int>{10,2});
	v.push_back(vector<int>{13,2});
	v.push_back(vector<int>{1,20});
	v.push_back(vector<int>{4,2});
	sort(v.begin(),v.end(),mycomp);
	for(auto &a: v)
	{
		for(auto x: a)
			cout<<x<<" ";
		cout<<endl;
	}
}