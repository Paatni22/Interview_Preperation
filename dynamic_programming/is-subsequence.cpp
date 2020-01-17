// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool go(int n,int m,string &s, string &t)
    {
        if(m==-1)   return true;   // child string become empty.
        if(n==-1)   return false;  // parent string become empty
        
        if(t[n] != s[m])    return go(n-1,m,s,t);
        
        return go(n-1,m-1,s,t) || go(n-1,m,s,t);
    }
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        
       return go(n,m,s,t); 
    }
};