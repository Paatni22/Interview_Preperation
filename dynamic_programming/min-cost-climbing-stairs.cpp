// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    vector<int> dp;
    int go(int index,vector<int> &cost)
    {
        if(index==0 || index==1)    return cost[index];
        if(dp[index] != -1) return dp[index];
        return dp[index] = cost[index] + min( go(index-1,cost),go(index-2,cost) );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,-1);
        
        cost.push_back(0);
        return go(n,cost);
    }
};
