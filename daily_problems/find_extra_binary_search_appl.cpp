/*Complete the function below*/

// ////////////application of binary search.
int findExtra(int a[], int b[], int n) {
    // add code here.
    if(a[n-1] != b[n-2])    return n-1;
    if(a[0] != b[0])    return 0;
    
    int i = 0,j = n-2;  
    //i points to equal elements.
    //j points to non equal elements.
    
    
    while(j-i > 1)
    {
        int mid = (i+j)/2;
        if(a[mid] != b[mid])
            j = mid;
        else
            i = mid;
    }
    return j;
}