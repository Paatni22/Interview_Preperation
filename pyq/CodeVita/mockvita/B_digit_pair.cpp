#include<bits/stdc++.h>
using namespace std;
int Min(int a,int b)
{
	return (a<b?a:b);
}
int bscore(int n)
{
	int a,b,c,max,min;
	a = n%10;
	b = (n/10) % 10;
	c = n/100;
	//cout<<a<<"-"<<b<<"-"<<c<<endl;
	if(a >= b && a>=c)
	{	max = a; min = Min(b,c);}
	else if(b>=a && b>=c)
	{	max = b; min = Min(a,c);}
	else
	{	max = c; min = Min(a,b);}

	int lscore = max*11 + min*7;
	if(lscore >=100)
	{
		lscore %= 100;
	}
	return lscore;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int score,msb,pairs=0;
	map<int,int> odd,even;

	for(int i=0;i<n;i++)
	{
		score = bscore(v[i]);
		//cout<<score<<" ";
		msb = score/10;

		if(score & 1)
			odd[msb]++;
		else	even[msb]++;
		
	}
	for(auto x:odd)
	{
		int curr = x.second;
		curr /= 2;
		curr = (curr>2?2:curr);

		pairs += curr;
	}
	for(auto x:even)
	{
		int curr = x.second;
		curr /= 2;
		curr = (curr>2?2:curr);

		pairs += curr;
	}
	cout<<pairs<<endl;
}