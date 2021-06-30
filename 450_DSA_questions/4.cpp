// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

void swap(int &a,int &b)
{
    // a = a+b;
    // b = a-b;
    // a = a-b;
    int temp = a;
    a = b;
    b = temp;
}
void sort012(int a[], int n)
{
    int zero=-1,i,two = n;
    for(i=0;i<two;i++)
    {
        if(a[i]==0)
        {
            zero++;
            swap(a[zero],a[i]);
        }
        else if(a[i] == 2)
        {
            two--;
            swap(a[i],a[two]);
            i--;
        }
    }
}