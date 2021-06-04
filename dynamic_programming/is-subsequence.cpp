// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=0;i<=m+1;i++)
            dp[0][i] = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(t[i-1] != s[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};