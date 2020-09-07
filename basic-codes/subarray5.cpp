/*
*****Number of subarrays having sum less than K*******
Q. Given an array of non-negative numbers and a non-negative number 
k, find the number of subarrays having sum less than k. We may 
assume that there is no overflow.

Examples :

Input : arr[] = {2, 5, 6}
        K = 10
Output : 4
The subarrays are {2}, {5}, {6} and
{2, 5},
*/

//sliding window approach.

// CPP program to count 
// subarrays having sum 
// less than k. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find number 
// of subarrays having sum 
// less than k. 
int countSubarrays(int arr[], int n, int k) 
{ 
	int start = 0, end = 0,count = 0, sum = arr[0]; 

	while (start < n && end < n) { 

		// If sum is less than k, 
		// move end by one position. 
		// Update count and sum 
		// accordingly. 
		if (sum < k) { 
			end++; 

			if (end >= start) 
				count += end - start; 

			// For last element, 
			// end may become n 
			if (end < n) 
				sum += arr[end]; 
		} 

		// If sum is greater than or 
		// equal to k, subtract 
		// arr[start] from sum and 
		// decrease sliding window by 
		// moving start by one position 
		else { 
			sum -= arr[start]; 
			start++; 
		} 
	} 

	return count; 
} 

int countSubarrays2(int nums[],int n, int k) 
{
    if (k == 0) return 0;
    int cnt = 0;
    int sum = 0;
    for (int i = 0, j = 0; j < n; j++) {
        sum += nums[j];
        while (i <= j && sum >= k) {
            sum -= nums[i++];
        }
        cnt += j - i + 1;
    }
    return cnt;
}
// Driver Code 
int main() 
{ 
	int array[] = { 1, 11, 2, 3, 15 }; 
	int k = 10; 
	int size = sizeof(array) / sizeof(array[0]); 
	// both functions are by sliding window app.
	cout << countSubarrays(array, size, k)<<endl; 
	cout << countSubarrays2(array, size, k)<<endl;
} 


unacademy super30 TS
telegram
testbook
Gate Overflow.
gfg (C,os,etc)
mcq in computer science timothy williams 


