class Solution {
public:
    const int inf=1e8;
    int start(int x,int y,vector<vector<int>> &a)
    {
        if(x==a.size()) return 0;
        if(y==-1 || y==a[0].size()) return inf;


         int ans=INT_MAX;
        ans = min(ans,a[x][y] + start(x+1,y-1,a));
        ans = min(ans,a[x][y] + start(x+1,y,a));
        ans = min(ans,a[x][y] + start(x+1,y+1,a));

         return ans;
    }

     int minFallingPathSum(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();

         int ans = INT_MAX;
        for(int i=0;i<col;i++)
        {
            ans  = min(ans,start(0,i,a));
        }
        return ans;
    }
};