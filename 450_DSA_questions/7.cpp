// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1#


/*
solns:
by using a var: rotate1
pure inplace : rotate2, rotate3
*/
void rotate1(int arr[], int n)
{
    int last = arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

void swap(int &a,int &b)
{
	int temp = a; a = b; b = temp;
}
void rotate2(int a[], int n)
{
    
    for(int i=n-1;i>0;i--)
        swap(a[i],a[i-1]);
 
}
void rotate3(int a[], int n)
{
    
    for(int i=0;i<n-1;i++)
        swap(a[i],a[n-1]);
 
}