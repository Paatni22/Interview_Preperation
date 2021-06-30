// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

// we do this ques by both ways of partition procedure of quick sort.

#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void partition1(int a[],int n)
{
	int pivot = 0; // all the elems before pivot var are -ve
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			swap(a[i],a[pivot]);
			pivot++;
		}
	}

}
void partition2(int *a,int n)
{
	int l=0,r=n-1;
	while(l<r)
	{
		while(l<n && a[l]<0)
			l++;
		while(r>=0 && a[r]>=0)
			r--;
		if(l<r)	
			swap(a[l++],a[r--]);
		
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//partition1(a,n);
	partition2(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}