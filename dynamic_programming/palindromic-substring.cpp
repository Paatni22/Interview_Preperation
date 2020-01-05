// https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
	vector<vector<int>> dp, vis;

	int isPal(int i,int j,string &s)
	{
		if(i>=j)	return 1;

		int &ans = dp[i][j];
		if(vis[i][j])	return ans;

		vis[i][j] = 1;
		if(s[i] != s[j])	return ans = 0;
		return ans = isPal(i+1,j-1,s);
	}
    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n));
        vis.resize(n,vector<int>(n,0));

        int ans = 0;
        for(int i=0;i<n;i++)
        {
        	for(j=i;j<n;j++)
        	{
        		if(isPal(i,j,s))	ans++;
        	}
        }
        return ans;


    }
};