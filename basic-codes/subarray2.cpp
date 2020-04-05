/*
 *******Count subarrays with equal number of 1’s and 0’s*******

Q.Given an array arr[] of size n containing 0 and 1 only. The problem is to count the subarrays having equal number of 0’s and 1’s.

Examples:

Input : arr[] = {1, 0, 0, 1, 0, 1, 1}
Output : 8
The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;

	vector<int> v(n);
	for(int &x:v)
		cin>>x;
	map<int,int> mp;
	int currSum = 0,sum = 0;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		currSum += v[i];
		if(currSum == 0)
			ans += 1;
		if(mp[currSum-sum]>0)
			ans += mp[currSum-sum];
		mp[currSum]++;
	}
	cout<<ans<<endl;
}