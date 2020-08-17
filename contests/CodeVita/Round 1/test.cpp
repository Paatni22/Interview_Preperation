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
		cout<<"till now "<<curr<<endl;
		if(maxSize < curr)	maxSize = curr;

	}
	return maxSize;
}
int main()
{
	int a[] = {3,4,4,5,3,1};
	cout<<calcMaxGrid(a,6)<<endl;
}
/*

	string text_rep[] = {"zero", "one", "two", "three", "four", "five",  "six", "seven",  "eight",  "nine",
 "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
"seventeen", "eighteen", "nineteen", "twenty", "twentyone",  "twentytwo", 
"twentythree", "twentyfour", "twentyfive", "twentysix", "twentyseven", 
"twentyeight", "twentynine",  "thirty", "thirtyone",  "thirtytwo","thirtythree", 
"thirtyfour", "thirtyfive", "thirtysix", "thirtyseven", "thirtyeight",  "thirtynine", 
"forty", "fortyone", "fortytwo", "fortythree", "fortyfour",  "fortyfive", "fortysix",
 "fortyseven", "fortyeight", "fortynine", "fifty", "fiftyone",  "fiftytwo", 
"fiftythree", "fiftyfour", "fiftyfive", "fiftysix", "fiftyseven", "fiftyeight",  "fiftynine",
 "sixty", "sixtyone", "sixtytwo", "sixtythree", "sixtyfour", "sixtyfive",  "sixtysix",
 "sixtyseven", "sixtyeight", "sixtynine", "seventy", "seventyone",  "seventytwo",
 "seventythree", "seventyfour","seventyfive", "seventysix", "seventyseven", 
"seventyeight", "seventynine",  "eighty", "eightyone", "eightytwo",  "eightythree", 
"eightyfour", "eightyfive",  "eightysix",  "eightyseven", "eightyeight",  "eightynine", 
"ninety", "ninetyone",  "ninetytwo",  "ninetythree", "ninetyfour", "ninetyfive", 
"ninetysix", "ninetyseven",  "ninetyeight", "ninetynine", "hundred"};

	
	*/