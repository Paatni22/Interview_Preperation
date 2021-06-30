// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
#include<bits/stdc++.h>
using namespace std;
int next_distinct(int a[],int i,int n)
{
	int j=i+1;
	while(j<n && a[i]==a[j])
	{
		j++;
	}
	return j;
}
void UnionAndInt(int a[], int n, int b[], int m)  {
    //code 
    
    vector<int> un;
    vector<int> in;
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0;
    while(i<n && j<m)
    {
    	if(a[i] == b[j])
    	{
    		un.push_back(a[i]);
    		in.push_back(a[i]);
    		i = next_distinct(a,i,n);
    		j = next_distinct(b,j,m);
    	}
    	else if(a[i]<b[j])
    	{
    		un.push_back(a[i]);
    		i = next_distinct(a,i,n);
    		
    	}
    	else
    	{
    		un.push_back(b[j]);
    		j = next_distinct(b,j,m);
    		
    	}
    	while(i<n)
    	{
    		un.push_back(a[i]);
    		i = next_distinct(a,i,n);
    	}
    	while(j<m)
    	{
    		un.push_back(b[j]);
    		j = next_distinct(b,j,m);
    	}

    }

    //printing......
    cout<<"union: ";
    for(int i=0;i<un.size();i++)
    {
        cout<<un[i]<<" ";
    }
    cout<<endl<<"interesection: ";
    for(int i=0;i<in.size();i++)
        cout<<in[i]<<" ";
    cout<<endl;
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    UnionAndInt(a,n,b,m);
}