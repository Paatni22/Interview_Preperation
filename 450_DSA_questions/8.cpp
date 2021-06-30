// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include<iostream>
#include<climits>
using namespace std;

int maxSubarraySum(int a[], int n){
    
    // Your code here
    int maxSum=INT_MIN, max_so_far=0;
    for(int i=0;i<n;i++)
    {
        max_so_far += a[i];
        if(max_so_far > maxSum )   maxSum = max_so_far;
        
        if(max_so_far < 0) max_so_far = 0;
    }
    return maxSum;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubarraySum(a,n)<<endl;
}