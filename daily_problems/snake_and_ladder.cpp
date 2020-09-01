#include <iostream>
#include<map>
#include<limits.h>
using namespace std;
int minOfNext6(int i,int *dp)
{
	int minim=INT_MAX;
	int j = i+1;
	while(j<31 && j<=i+6)
	{
		if(dp[j]< minim)
			minim = dp[j];
		j++;
	}
	return minim;
}
int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n,from,to;
	    cin>>n;
	    map<int,int> ladder;
	    for(int i=0;i<n;i++)
	    {
	        cin>>from>>to;
	        if(from<to) ladder[from] = to;
	    }
	    int dp[31] = {0};
	    
	    for(int i=29;i>=1;i--)
	    {
	        if(ladder.count(i))
	            dp[i] = min(1+minOfNext6(i,dp), dp[ladder[i]]);
	        else
	            dp[i] = 1+minOfNext6(i,dp);
	    }
	   
	    cout<<endl<<dp[1]<<endl;
	}
	return 0;
}