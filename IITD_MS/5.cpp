#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	//I just need the hour;
	int freq[24]={0};
	for(int i=0;i<n;i++)
	{
		int hour;
		cin>>hour;
		freq[hour]++;
	}
	int maxFreq = 0;
	int ans;
	for(int i=n-1;i>=0;i--)
	{
		if(freq[i] > maxFreq)
		{	maxFreq = freq[i];
			ans = i;
		}

	}	
	cout<< ans;

}