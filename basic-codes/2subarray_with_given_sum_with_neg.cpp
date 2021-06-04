/*
Subarrays with given sum
link : https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0
Given an unsorted array arr[] of N integers and a sum. The task is to count the number
 of subarrays which add to a given number.*/
#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int target,preSum = 0,ans=0;
	    cin>>target;
	    
	    unordered_map<int,vector<int>> mp;
	    mp[0].push_back(-1);
	    for(int i=0;i<n;i++)
	    {
	        preSum += a[i];
	        
	        int extra = preSum - target;
	        if(mp.count(extra))
	        {
	            int found = mp[extra].size();
	            for(int j=0;j<found;j++)
	            {
	                //cout<<"found from:"<<mp[extra][j]+1<<" "<<i<<endl;
	            }
	            
	            ans += found;
	        }
	        mp[preSum].push_back(i);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
