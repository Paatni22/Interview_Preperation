/*
Problem statement : 
Given an integer(n) denoting the no. of particles initially
Given an array of sizes of these particles
These particles can go into any number of simulations (possibly none)
In one simualtion two particles combines to give another particle with size as the difference between the size of them (possibly 0).
Find the smallest particle that can be formed.

constraints
n<=1000
size<=1e9
Example 1
3
30 10 8
Output
2
Explaination- 10 - 8 is the smallest we can achive

Example 2
4
1 2 4 8
ouput
1
explaination
We cannot make another 1 so as to get 0 so smallest without any simulation is 1

example 3
5
30 27 26 10 6
output
0
30-26=4
10-6 =4
4-4 =0


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &x:n)
		cin>>x;
	vector<int> temp;
	int min = INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{

		}
	}
}