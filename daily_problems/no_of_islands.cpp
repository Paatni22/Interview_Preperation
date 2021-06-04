void DFS(vector<vector<int>> &a,int i,int j)
{
    int n=a.size(),m = a[0].size();
    if(i<0 || i>n-1 || j<0 || j>m-1 || a[i][j]==0)  return;

    a[i][j] = 0;
    DFS(a,i+1,j);DFS(a,i,j+1);DFS(a,i-1,j);DFS(a,i,j-1);
    DFS(a,i+1,j+1);DFS(a,i-1,j-1);DFS(a,i+1,j-1);DFS(a,i-1,j+1);
    
}
int findIslands(vector<int> A[], int n, int m) {
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j] = A[i][j];
        }
    }
    int ans=0;
    ////////////////
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] )
            {
                ans++;
                DFS(a,i,j);
            }
        }
    }
    return ans;
    // Your code here
}