#include<bits/stdc++.h>
using namespace std;
void help(vector<vector<int>> &a,vector<vector<int>> &left,vector<vector<int>> &right,vector<vector<int>> &up,vector<vector<int>> &down,vector<vector<int>> &vis,int i,int j,int curr,int &max)
{
  int m = a[0].size();
  int n = a.size();
  if(i<0 || i>n-1 || j<0 || j>m-1)  return;
  if(vis[i][j]) return;
  vis[i][j] = 1;

  if(curr < a[i][j] ) a[i][j] = curr;
  if(left[i][j])  help(a,left,right,up,down,vis,i,j-1,curr+1,max);
  if(right[i][j])  help(a,left,right,up,down,vis,i,j+1,curr+1,max);
  if(up[i][j])  help(a,left,right,up,down,vis,i-1,j,curr+1,max);
  if(down[i][j])  help(a,left,right,up,down,vis,i+1,j,curr+1,max);
  if(max < curr)  max = curr;
}
int solve (int n, int m, int Ap, int Bp, vector<string> &maze, vector<int> &A, vector<int> &B) {
   // Write your code here
   vector<vector<int>> left(n,vector<int>(m,1)) , right(n,vector<int>(m,1)) , up(n,vector<int>(m,1)) , down(n,vector<int>(m,1));
  int mm = 2*m+1;
  int mn = n+1;
  
  
  for(int i=1;i<mn;i++)
  {
    string line; line = maze[i];
    string topmost;
  topmost = maze[i-1];
    int jj=0;
    for(int j=0;j<mm-1;j+=2)
    {
      left[i-1][jj] = (line[j]=='|' || jj==0 ? 0 : 1);
      right[i-1][jj] = (line[j+2]=='|' || jj==(m-1) ? 0 : 1);
      down[i-1][jj] = (line[j+1]=='_' || i-1==n-1 ? 0 : 1);
      up[i-1][jj] = (topmost[j+1]=='_' || i-1==0 ? 0 : 1);
      jj++;
    }
  }
  // for(auto &x:right) {
  // for(auto y:x) cout<<y<<" ";
  // cout<<endl;}
  // for(auto &x:left) {
  // for(auto y:x) cout<<y<<" ";
  // cout<<endl;}
  // for(auto &x:up) {
  // for(auto y:x) cout<<y<<" ";
  // cout<<endl;}
  // for(auto &x:down) {
  // for(auto y:x) cout<<y<<" ";
  // cout<<endl;}
  vector<vector<int>> a(n,vector<int>(m,INT_MAX));
  int max= 0;
  vector<vector<int>> vis(n,vector<int>(m,0));
  for(int i=0;i<A.size();i++)
  {
    help(a,left,right,up,down,vis,A[i],B[i],0,max);
  }
  // for(auto &x:a) {
  // for(auto y:x) cout<<y<<" ";
  // cout<<endl;}

return max;
  
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    int Ap;
    cin >> Ap;
    int Bp;
    cin >> Bp;
    vector<string> Maze(N+1);
    cin.ignore();
    for (int i_Maze = 0; i_Maze < N+1; i_Maze++) {
    	string str;
      getline(cin, str);
      Maze[i_Maze] = str;
    }
    int K;
    cin >> K;
    vector<int> A(K);
    vector<int> B(K);
    for(int i_A = 0; i_A < K; i_A++)
    {
    	cin >> A[i_A] >> B[i_A];
    }
  

    int out_;
    out_ = solve(N, M, Ap, Bp, Maze, A, B);
    cout << out_;
}