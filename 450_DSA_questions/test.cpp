#include<bits/stdc++.h>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(1);
	pq.push(34);
	pq.push(233);
	pq.push(23);
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}
}