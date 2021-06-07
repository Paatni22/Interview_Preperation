//  https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

/* Approaches for min comparisons: 
1 divide and conquer
2 tournament method
3 comare in paiirs.
*/
#include<bits/stdc++.h>
using namespace std;
struct paiir{
	int min;
	int max;
};
struct paiir minmax(int *a,int lb,int ub)
{
	int n = ub-lb+1;
	struct paiir ans;
	if(n==1)
	{
		ans.min = ans.max =  a[lb];
		return ans;
	}
	else if(n==2)
	{
		if(a[lb] < a[ub])
		{
			ans.min = a[lb]; ans.max = a[ub];
			return ans;
		}
		else
		{
			ans.min = a[ub]; ans.max = a[lb];
			return ans;
		}	
	}
	else
	{
		int mid = (lb+ub)/2;
		struct paiir lefthalf = minmax(a,lb,mid);
		struct paiir righthalf = minmax(a,mid+1,ub);
		
		if(lefthalf.min > righthalf.min)	ans.min = righthalf.min;
		else	ans.min = lefthalf.min;

		if(lefthalf.max > righthalf.max)	ans.max = lefthalf.max;
		else	ans.max = righthalf.max;
		return ans;
	}
}
int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	struct paiir ans = minmax(a,0,n-1);
	cout<<"min = "<<ans.min<<endl;
	cout<<"max = "<<ans.max<<endl;

}
/*
spatni@SPATNI:~/Documents/Interview_Preperation/450_DSA_questions$ g++ 2.cpp
spatni@SPATNI:~/Documents/Interview_Preperation/450_DSA_questions$ ./a.out
10
3 4 56 7 1 34 45 566 9 2
min = 1
max = 566
*/