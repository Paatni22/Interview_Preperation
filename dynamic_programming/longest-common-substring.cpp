// https://leetcode.com/problems/longest-common-subsequence/submissions/

class Solution {
public:
    int lcs(int i,int j,string &a, string &b)
    {
        if(i==-1 || j==-1)    return 0;
        if(a[i] == b[j])    return 1+lcs(i-1,j-1,a,b);
        return max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        return lcs(n1-1,n2-1,text1,text2);
        
        
        
    }
};