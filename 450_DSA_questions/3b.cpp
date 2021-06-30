#include<bits/stdc++.h>
using namespace std;
int Partition(int a[],int lb,int ub)
{
	int key = a[ub];
	int pivot = lb-1;
	for(int j=lb;j<ub;j++)
	{
		if(a[j] <= key)
		{
			pivot++;
			swap(a[pivot],a[j]);
		}
	}

	a[ub] = a[pivot+1];
	a[pivot+1] = key;
	return pivot+1;
}
int kthSmallest(int arr[], int l, int r, int k) {
    //code here

   int mid = Partition(arr,l,r);
   if(mid==k) return arr[k];
   else if(mid>k)	return kthSmallest(arr,l,mid-1,k);
   else				return kthSmallest(arr,mid+1,r,k);
}
// worst case time: O(n^2)
// but avg case time = n + n/2 + n/4 + n/8 + .... = 2n = O(n)
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	int kth_min = kthSmallest(a,0,n-1,k-1);
	cout<<kth_min<<endl;
}
/*
spatni@SPATNI:~/Documents/Interview_Preperation/450_DSA_questions$ ./a.out
10
6 7 8 9 5 4 3 2 1 0
4
3
*/