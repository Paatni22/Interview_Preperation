#include<iostream>
#include<map>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,var;		
		cin>>n;
		int rem[3] = {0};
		for(int i=0;i<n;i++)
		{
			cin>>var;
			rem[var%3]++;
		}
		int zeros,nonzeros;
		if(rem[1]==0 && rem[2] == 0)    //if only multiple of 3 are present.
			cout<<"No"<<endl;
		else if(rem[1]==0 || rem[2] == 0)  // either rem2 is 0 or rem1 is 0
		{
			zeros = rem[0];
			nonzeros = rem[1]+rem[2];
			if(zeros > nonzeros+1)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
		else if(rem[0] == 0)   // no multiples of 3.
		{
			cout<<"No"<<endl;
		}
		else       //all remainders, 0,1 and 2 are >=1.
		{
			nonzeros = rem[1] + rem[2];
			zeros = rem[0]-1;
			if(zeros > nonzeros)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;

		}
	}
}
