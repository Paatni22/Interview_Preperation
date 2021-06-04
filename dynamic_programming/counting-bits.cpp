// https://leetcode.com/problems/counting-bits/submissions/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);  
        
        dp[0] = 0;
        
        for(int i=1;i<=num;i++)  
            dp[i] = dp[i>>1] + (i&1);
       
        return dp;
    }
};