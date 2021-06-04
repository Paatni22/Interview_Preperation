/*
Q. WAP to print possibilities for choosing an ordered set of
 r objects (a permutation) from a total of n objects.

  Note : repetition is not allowed.

*/
#include <bits/stdc++.h> 
#define pb push_back
#define pob pop_back
//#include "class.cpp"
using namespace std; 

    int power(int x,map<int,int> &dp)
    {
        if(dp.count(x))
            return dp[x];
        if(x==1)    return 0;
        if(x%2==0)  return dp[x] = 1+power(x/2,dp);
        else    return dp[x] = 1+power(3*x+1,dp);
    }
    bool comp(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    int getKth(int lo, int hi, int k) {
        map<int,int> dp;
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++)
        {
            int p = power(i,dp);
            v.push_back(make_pair(i,p));
        }
        sort(v.begin(),v.end(),comp);
        for(auto x:v)
        {
        	cout<<x.first<<", "<<x.second<<endl;
        }
        return v[k-1].first;
	}
int main()
{
    int lo,hi,k;
    cin>>lo>>hi>>k;
    int ans = getKth(lo,hi,k);
    cout<<ans<<endl;

}
