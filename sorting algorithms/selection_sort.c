#include<stdio.h>

void selection_sort(int *,int);
/*
TC(B,A,W): n^2,n^2,n^2
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

	selection_sort(a,n);

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
void selection_sort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min = j;
		}
		if(min != i)	swap(&a[i],&a[min]);
	}
}
