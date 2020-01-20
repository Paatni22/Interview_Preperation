// https://leetcode.com/problems/longest-common-subsequence/submissions/

class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i,int j,string &a, string &b)
    {
        if(i==-1 || j==-1)    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(a[i] == b[j])    return dp[i][j] = 1+lcs(i-1,j-1,a,b);
        return dp[i][j] = max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        dp.resize(n1,vector<int>(n2,-1));
        
        return lcs(n1-1,n2-1,text1,text2);
        
        
        
    }
};// https://leetcode.com/problems/longest-common-subsequence/submissions/

class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i,int j,string &a, string &b)
    {
        if(i==-1 || j==-1)    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(a[i] == b[j])    return dp[i][j] = 1+lcs(i-1,j-1,a,b);
        return dp[i][j] = max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        dp.resize(n1,vector<int>(n2,-1));
        
        return lcs(n1-1,n2-1,text1,text2);
        
        
        
    }
};