// qxH/hUg

#include<bits/stdc++.h>
using namespace std;
int calcMaxGrid(int *a,int n)
{
	int curr,maxSize = 0;
	for(int i=0;i<n;i++)
	{
		curr = a[i];
		int run = 1;
		for(int j=i+1;j<n && j<i+curr ; j++)
		{
			if(a[j] < curr)
				curr = a[j];
			run++;
			//cout<<j<<" curr = "<<curr<<endl;
		}
		//cout<<"i= "<<i<<" curr="<<curr<<" run="<<run<<endl;
		if(run < curr)	curr = run;
		if(maxSize < curr)	maxSize = curr;
	}
	return maxSize;
}

int main()
{
	int n;
	cin>>n;
	int a[n][n];
	char ch;
	int hor[n]={0},vert[n]={0};
	int noOfDs = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ch;
			a[i][j] = ch-'C';
			vert[j] +=  a[i][j];
			hor[i]  +=	a[i][j];
			if(ch=='D')	noOfDs++; 
		}
	}
	
	for(int i=0;i<n;i++)	cout<<hor[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)	cout<<vert[i]<<" ";
	cout<<endl;
	int v = calcMaxGrid(vert,n);
	int h = calcMaxGrid(hor,n);
	//cout<<"vert: "<<v<<endl;
	//cout<<"hor: "<<h<<endl;

	cout<< min((int)floor(sqrt(noOfDs)),max(v,h) )<<endl;
}