#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

/*
Rec eqn
ways(lv,i) =	w(0,i-1) + w(1,i-1) , if(lv==0)
				w(0,i-1)	, if(lv==1)
				1			,if(i==-1)


*/
vector<vector<int>> dp;
int ways(int lastValue,int ind)
{
    if(ind==-1) return 1;
    
    if(dp[ind][lastValue] != -1)    // if computed before.
        return dp[ind][lastValue];
        
    if(lastValue == 0)
        return dp[ind][lastValue] = (ways(0,ind-1) + ways(1,ind-1)) % M;
    else 
        return dp[ind][lastValue] = ways(0,ind-1);
}
int main() {
	//DP Solution
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    dp.resize(n,vector<int>(2,-1));
	    cout<< ways(0,n-1)<<endl; // 0 means no restriction on first bit.
	}
	return 0;
}
/*
// Mukesh soln:
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

int main() {
	
	int ans[101] = {0};
	ans[1] = 2;
	int prevOne = 1;
	int prevZero = 1;
	for (int i = 2; i <= 100; i++)
	{
	    int nextPrevOne = prevZero;
	    int nextPrevZero = (prevZero + prevOne) % mod;
	    
	    ans[i] = (prevOne%mod);
	    ans[i] = (ans[i] + (prevZero%mod * 2)) % mod;
	    
	    prevOne = nextPrevOne;
	    prevZero = nextPrevZero;
	}
	
	int t; cin>>t;
	
	while(t--)
	{
	    int n; cin>>n;
	    cout<<ans[n]<<"\n";
	}
	
	return 0;
}
*/