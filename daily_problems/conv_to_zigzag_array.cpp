/*
Convert array into Zig-Zag fashion

link:https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0

Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3
*/
#include <iostream>
#include<algorithm>
using namespace std;
void swap(int &a,int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}

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
	    
	   if(a[1]<a[0])    swap(a[0],a[1]);	//check 1st elem should be < 2nd elem.

	   for(int i=0;i<n-2;i++)	//checking for next every group of 3 elems.
	    if((a[i]-a[i+1])*(a[i+1]-a[i+2]) > 0)
            swap(a[i+1],a[i+2]);
	    
	    
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	    
	}
	return 0;
}