/*
Maximum Index
link : https://practice.geeksforgeeks.org/problems/maximum-index/0
Given an array A[] of N positive integers. The task is to find the 
maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6
Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required 
ondition(A[i] <= A[j]) thus giving the maximum difference of j - i 
which is 6(7-1).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code 
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(auto &x:a)
	        cin>>x;
	    int max = 0;
	    // brute force
	    //read optimal soln at :https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
	    for(int i=0;i<n;i++)
	    {
	        for(int j=n-1;j>=i;j--)
	        {
	            if(a[i]<=a[j])
	            {
	                if(max < j-i)
	                    max = j-i;
                    break;
	            }
	        }
	        int maxWeCanGet = (n-1)-(i+1);
	        if(max >= maxWeCanGet)// if we can't get more than what max have
	          break;
	    }
	    cout<<max<<endl;
	}
	return 0;
}