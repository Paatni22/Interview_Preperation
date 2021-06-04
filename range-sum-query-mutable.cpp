// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int> dp;
    vector<int> a;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1);
        a=nums;
        dp[0] = 0;
        for(int i=0;i<n;i++)
        {
            dp[i+1] = dp[i] + nums[i];
        }
        
    }
    
    void update(int i, int val) {
        int diff = a[i] - val;
        a[i] = val;
        for(int j=i;j<a.size();j++)
            dp[j+1] -= diff;
        
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */