class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2));
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = dp[i][n+1] = INT_MAX;
            dp[n][i] = 0;
        }
        
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
                dp[i][j+1] = a[i][j] + min(dp[i+1][j],min(dp[i+1][j+1], dp[i+1][j+2]) );
         
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
            ans = min(ans,dp[0][i]);
        return ans;
    }
};