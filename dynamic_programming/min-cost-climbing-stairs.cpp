// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int go(int index,vector<int> &cost)
    {
        if(index==0 || index==1)    return cost[index];
        return cost[index] + min(go(index-1,cost),go(index-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        return go(n,cost);
    }
};
