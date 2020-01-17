// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    vector<vector<int>> dp;
    bool go(int n,int m,string &s, string &t)
    {
        if(m==-1)   return 1;   // child string become empty.
        if(n==-1)   return 0;  // parent string become empty
        
        if(dp[n][m] != -1)  return dp[n][m];
        
        if(t[n] != s[m])    return dp[n][m] = go(n-1,m,s,t);
        
        return dp[n][m] = go(n-1,m-1,s,t) || go(n-1,m,s,t);
    }
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return go(n,m,s,t); 
    }
};