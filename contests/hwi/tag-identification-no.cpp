// for question refer to the pdf in the same directory.

#include<iostream>
using namespace std;
int main()
{
	string inp;
	cin>>inp;
	int noOf8=0;
	for(char ch:inp)
		if(ch=='8')
			noOf8++;
	int maxTids = inp.size() / 11;

	cout<< min(maxTids, noOf8) <<endl;
}