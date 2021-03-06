/*
link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S.

*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    //cout<<"running tc = "<<t+1;
	    int n,target;
	    cin>>n>>target;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int currSum = 0,start = 0;
	    for(int i=0;i<n;i++)
	    {
	        currSum += a[i];
	        
	        while(currSum > target && start <= i)
	        {
	            currSum -= a[start];
	            start++;
	        }
	        
	        if(currSum == target){
	            cout<<start+1<< " "<<i+1<<endl;
	            
	            break;
	        }
	        
	    }
	    if(currSum != target)
	        cout<<-1<<endl;
	}
	return 0;
}
