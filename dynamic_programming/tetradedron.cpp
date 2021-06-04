// https://codeforces.com/problemset/problem/166/E

#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

vector<vector<long long>> dp;
vector<vector<int>> adj{
	{1,2,3},
	{0,2,3},
	{0,1,3},
	{0,1,2}
};
int ways(int src, int dest, int steps)
{
	if(steps==0 && src!=dest)
		return 0;
	if(steps==0 && src==dest)
		return 1;
	if(dp[src][steps] != -1)
		return dp[src][steps];
	int ans =0;
	for(int i=0;i<4;i++)
	{
		if(i==src)	continue;
		ans += ways(i,dest,steps-1);
		if(ans >= mod)	ans -= mod;
	}
	return dp[src][steps] = ans;

}

int main()
{
	int n;
	cin >> n;
	dp.resize(4,vector<long long>(n+1,-1));

	cout<< ways(1,1,n);
}