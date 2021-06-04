//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  int n = arr.size();
  vector<int> dp(n+1);
  dp[0] = 0;
  dp[1] = (arr[0]<0 ? 0 : arr[0]);
  for(int i=2;i<=n;i++)
  	dp[i] = max(arr[i-1]+dp[i-2],dp[i-1]);

  return dp[n];
}