#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    void comb(vector<int> &a,int i,vector<int> &curr,set<vector<int>> &ans)
    {
        if(i<0) {
            ans.insert(curr);
            return;
        }
        comb(a,i-1,curr,ans);
        curr.push_back(a[i]);
        comb(a,i-1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        set<vector<int>> ans;
        vector<int> curr;
        comb(a,a.size()-1,curr,ans);

        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};


