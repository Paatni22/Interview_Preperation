// https://leetcode.com/problems/longest-palindromic-substring/submissions/
public:
    vector<vector<int>> dp, vis;

    int isPal(int i,int j,string &s)
    {
        if(i>=j)    return 1;

        int &ans = dp[i][j];
        if(vis[i][j])   return ans;

        vis[i][j] = 1;
        if(s[i] != s[j])    return ans = 0;
        return ans = isPal(i+1,j-1,s);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n));
        vis.resize(n,vector<int>(n,0));

        pair<int,int> ansRange;
        int max = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPal(i,j,s))    
                {
                    if(max < j-i+1)
                    {
                        max = j-i+1;
                        ansRange = make_pair(i,j);
                    }
                }
            }
        }
        string ans = "";
        for(int i=ansRange.first;i<=ansRange.second;i++)
        {
            ans += s[i];
        }
        return ans;


    }
};