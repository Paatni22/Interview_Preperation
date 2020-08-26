//Task Scheduling Problem.
//asked in Amazon in form of platforms and trains.(complitely similar.)

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	// let time are given without colon(:)
	// if not I will convert it to like this.
	// let data is sorted acc. to arrival time.

	//algo
	int j,ans=0,n = sizeof(arr)/sizeof(arr[0]);
	int platform[n] = {0};	//in worst case we require n platforms.
	for(int i=0;i<n;i++)
	{
		j=0;
		while(platform[j] > arr[i])
			j++;
		if(ans<j)	ans = j;

		platform[j] = dep[i];
		cout<<"scheduled in platform "<<j+1<<endl;
	}
	ans++;		// ans would be max Index we can go + 1
	cout<<"max platforms reqd: "<<ans<<endl;


}