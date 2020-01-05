class Solution {
public:
    const int inf=1e8;
    vector<vector<int>> dp,visit;
    int start(int x,int y,vector<vector<int>> &a)
    {
        if(x==a.size()) return 0;
        if(y==-1 || y==a[0].size()) return inf;

        if(visit[x][y]) return dp[x][y];

        int ans=INT_MAX;
        ans = min(ans,a[x][y] + start(x+1,y-1,a));
        ans = min(ans,a[x][y] + start(x+1,y,a));
        ans = min(ans,a[x][y] + start(x+1,y+1,a));

        return ans;
        visit[x][y] = 1;
        return dp[x][y] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();

        dp.resize(row, vecor<int>(col));
        visit.resize(row, vecor<int>(col,0));

        int ans = INT_MAX;
        for(int i=0;i<col;i++)
        {
            ans  = min(ans,start(0,i,a));
        }
        return ans;
    }
}; 