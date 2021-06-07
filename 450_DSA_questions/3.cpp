#include<bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    priority_queue<int> pq;
    int i;
    for(i=l;i<l+k;i++)
        pq.push(arr[i]);
    for(i=l+k;i<=r;i++)
    {
        if(pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	int kth_min = kthSmallest(a,0,n-1,k);
	cout<<kth_min<<endl;
}
/*
spatni@SPATNI:~/Documents/Interview_Preperation/450_DSA_questions$ ./a.out
10
6 7 8 9 5 4 3 2 1 0
4
3
*/