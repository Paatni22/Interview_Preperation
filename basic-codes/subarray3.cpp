/*
 *****Split an array into two equal Sum subarrays*****

NOTE : this one is very simple.
Q.Given an array of integers greater than zero, find if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays is the same. Print the two subarrays.

Examples :

Input : Arr[] = { 1 , 2 , 3 , 4 , 5 , 5  }
Output :  { 1 2 3 4 } 
          { 5 , 5 }

Input : Arr[] = { 4, 1, 2, 3 }
Output : {4 1}
         {2 3}

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;

	vector<int> v(n);
	int sum=0;

	for(int &x:v)
	{
		cin>>x;
		sum += x;
	}
	if(sum&1)
	{
		cout<<"not possible"<<endl;
		return 0;
	}
	sum = sum/2;

	map< int , vector<int> > mp;
	int currSum = 0;
	int ind = 0;
	bool found = false;
	for(int i=0;i<n;i++)
	{
		currSum += v[i];
		if(currSum == sum)
		{
			ind = i+1;
			found = true;
			break;

		}
	}
	if(found==false)
	{
		cout<<"not possible"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(i==ind)
			cout<<endl;
		cout<<v[i]<<" ";
	}
	return 0;
	
}