/*
https://leetcode.com/problems/permutations/submissions/

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

class Solution {
public:
    void perm(vector<vector<int>> &ans,vector<int> &curr,int ind,vector<int> &v,int tot)
    {
        if(ind==tot){
            ans.push_back(curr);
            return;
        }   
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            curr.push_back(v[i]);
            v.erase(v.begin()+i);
            perm(ans,curr,ind+1,v,tot);
            v.insert(v.begin()+i,curr[curr.size()-1]);
            curr.pop_back();
        } 
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        perm(ans,curr,0,nums,nums.size());
        return ans;
    }
};