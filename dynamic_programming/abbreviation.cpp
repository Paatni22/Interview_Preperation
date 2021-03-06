
bool isSmall(char ch)
{
  if(ch>='a' && ch <='z') return true;
  else  return false;
}
vector<vector<bool>> dp;
vector<vector<bool>> vis;

bool Same(int i,int j,string a,string b)
{
  if(i==0 && j==0)  return true;  //both can be same
  if(i==0 ) return false;  //bcoz we can't delete the characters of b (and j!=0)
  if(vis[i][j]) return dp[i][j];
  else  vis[i][j] = true;
  if(j==0)      //b is completed & a is not, we have to check in a that all rem are small or not.
  {
    if( isSmall(a[i]) ) return dp[i][j] = Same(i-1,j,a,b);
    else  return dp[i][j] = false;
  }

  if( isSmall(a[i]) )
  {
    if( ( a[i]-('a'-'A') ) == b[j])
      return dp[i][j] = Same(i-1,j-1,a,b) || Same(i-1,j,a,b);
    else
      return dp[i][j] = Same(i-1,j,a,b);
  }
  else
  {
    if(a[i] == b[j])
      return dp[i][j] = Same(i-1,j-1,a,b);
    else
      return dp[i][j] = false;
  }
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
  int n = a.size();
  int m = b.size();
  dp.resize(n,vector<bool>(m));
  vis.resize(n,vector<bool>(m,false));

  if(Same(n-1,m-1,a,b)) return "YES";
  else  return "NO";

}
