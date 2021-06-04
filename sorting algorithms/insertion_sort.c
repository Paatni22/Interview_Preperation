#include<stdio.h>

void insertion_sort(int *,int);
/*
TC(B,A,W): n,n^2,n^2
SC: O(1)
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

	insertion_sort(a,n);

	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d, ",a[i]);
	printf("\n");
}

void insertion_sort(int *a,int n)
{
	for(int i=1;i<n;i++)
	{
		int j,key = a[i];
		for(j=i-1;j>=0 && a[j] > key;j--)
			a[j+1] = a[j];
		a[j+1] = key;
	}
}
