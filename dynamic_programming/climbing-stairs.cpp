//https://leetcode.com/problems/climbing-stairs/solution/

class Solution {
public:
    vector<int> dp;
    int go(int n)
    {
        if(n<0)     return 0;
        if(n==0)    return 1;
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = go(n-1) + go(n-2);
        
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return go(n);
    }
};