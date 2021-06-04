#include<stdio.h>

void quick_sort(int *,int,int);
/*
TC(B,A,W): nlogn,nlogn,n^2
* if we use randomized QS, then TC would be mostly O(nlogn) *
* it would not be worst(O(n^2)) in sorted array, which is more often*
SC: O(n)
*/

int main()
{
	printf("size of array: ");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("enter array elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	quick_sort(a,0,n-1);

	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d, ",a[i]);
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition1(int *a,int lb,int ub)
{
	int pivot = a[ub];
	int i = lb;
	for(int j = lb;j<ub;j++)
	{
		if(a[j] <= pivot)
		{
			swap(&a[i],&a[j]);
			i++;
		}
	}
	swap(&a[i],&a[ub]);
	return i;
}
int partition2(int *a,int lb,int ub)
{
	int pivot = a[ub];
	int i = lb,j = ub-1;
	while(i<j)
	{
		while(a[i]<=pivot && i<ub)
			i++;
		while(a[j] > pivot && j>=0)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[i],&a[ub]);
	return i;
}
void quick_sort(int *a,int lb,int ub)
{
	if(lb<ub)
	{
		int mid = partition2(a,lb,ub);
		quick_sort(a,lb,mid-1);
		quick_sort(a,mid+1,ub);
	}
}
