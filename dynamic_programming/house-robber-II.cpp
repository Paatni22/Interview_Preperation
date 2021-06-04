// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n==0)    return 0;
        if(n==1)    return a[0];
        if(n==2)    return max(a[0],a[1]);
        
        //case 1: if we consider 1st element.
        vector<int> dp(n,0);
        dp[0] = a[0];
        dp[1] = dp[0];
        dp[2] = dp[0]+ a[2];
        for(int i=3 ; i<n-1;i++)
            dp[i] = max(dp[i-1],dp[i-2]+a[i]);
        
        //case 2: if we don't consider 1st element.
        vector<int> mp(n,0);
        mp[0] = 0;
        mp[1] = a[1];
        
        for(int i=2 ; i<n;i++)
            mp[i] = max(mp[i-1],mp[i-2]+a[i]);
        
        // ans is max among two cases
        return max(dp[n-2],mp[n-1]);
        
    }
};                                                                                                                                
