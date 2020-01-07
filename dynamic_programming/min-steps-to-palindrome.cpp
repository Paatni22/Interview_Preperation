//Minimum Insertion Steps to Make a String Palindrome
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    vector<vector<int>> dp;
    int steps(int i,int j,string &s){
        if(i>=j)    return 0;
        if(dp[i][j] !=-1)   return dp[i][j];
        if(s[i] == s[j])    return dp[i][j] = steps(i+1,j-1,s);
        return dp[i][j] = 1+min(steps(i+1,j,s) , steps(i,j-1,s));
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return steps(0,n-1,s);
    }
};