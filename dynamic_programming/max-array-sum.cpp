//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

int maxSum(int i,vector<int> &arr)
{
  if(i<0) return 0;
  if(arr[i]<0)  return maxSum(i-1,arr);

  return max( arr[i]+maxSum(i-2,arr), maxSum(i-1,arr) );
}
// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  int n = arr.size();
  return maxSum(n-1,arr);
}