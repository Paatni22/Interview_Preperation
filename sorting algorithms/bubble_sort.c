#include<stdio.h>

void bubble_sort(int *,int);
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

	bubble_sort(a,n);

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
void bubble_sort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int swapped = 0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swapped = 1;
			}
		}
		if(swapped==0)	break;
	}
}
