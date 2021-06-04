#include <bits/stdc++.h>
#include<vector>
#include<cmath>
#include<limits.h>
  using namespace std;

vector<vector<bool>> dp;
vector<vector<bool>> vis;

long long posib(long long x,long long y)
{
    if(x<1 || y<1)  return false;
    else if(x==1 && y==1)   return dp[x][y] = true;
    else if(vis[x][y]) return dp[x][y];
    else{
        vis[x][y] = true;
        return dp[x][y] = (posib(x,y-x) || posib(x-y,y));
    }   
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x, y;
        cin>>x>>y;
        dp.resize(x+1,vector<bool>(y+1,false));
        vis.resize(x+1,vector<bool>(y+1,false));
        cout<<posib(x,y)<<endl;
    }
    
}
/*
int posib(int x,int y)
{
    if(x<1 || y<1)  return false;
    else if(x==1 && y==1)   return true;
    else    return (posib(x,y-x) || posib(x-y,y));
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, y;
        cin>>x>>y;
        //dp.resize(x+1,vector<bool>(y+1,false));
        cout<<posib(x,y)<<endl;
    }
    
}
*/