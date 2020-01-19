vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==0)    return;
        int m = mat[0].size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i+1][j+1] = dp[i+1][j] + mat[i][j];
           
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                dp[j+1][i+1] = dp[j][i+1] + dp[j+1][i+1];
        
       
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(dp.size()==1) return 0;
        int br = dp[r2+1][c2+1];    //bottom-right.
        int bl = dp[r2+1][c1];  //bottom-left.
        int tr = dp[r1][c2+1];  //top-right.
        int tl = dp[r1][c1];    //top-left.
      
        return br - (bl+tr) + tl ;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */