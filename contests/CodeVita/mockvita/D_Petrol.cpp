#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	string input;
	getline(cin,input);
	stringstream ssin(input);
	int a;
	while(ssin>>a)
	{
		v.push_back(a);
	}
	
	int one=0,two=0,val,n = v.size();
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0;i--)
	{
		val = v[i];
		if(one<two)
			one += val;
		else two += val;
	}
	cout<<max(one,two);
}