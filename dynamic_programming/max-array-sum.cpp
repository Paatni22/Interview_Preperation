//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
vector<int> dp;
int maxSum(int i,vector<int> &arr)
{
  if(i<0) return 0;
  if(dp[i] != -1)	return dp[i];
  if(arr[i]<0)  return dp[i] = maxSum(i-1,arr);

  return dp[i] = max( arr[i]+maxSum(i-2,arr), maxSum(i-1,arr) );
}
// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  int n = arr.size();
  dp.resize(n,-1);
  return maxSum(n-1,arr);
}