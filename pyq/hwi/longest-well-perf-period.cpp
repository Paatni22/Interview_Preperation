// for question refer to the pdf in the same directory.

#include<iostream>
#include<vector>

using namespace std;
int max(int a,int b){	return (a>b?a:b);}

int main()
{
	int n;
	cin>> n;
	vector<int> v(n);
	for(int &x:v)
		cin>>x;
	int threshold;
	cin>>threshold;

	vector<int> bitmap(n);
	for(int i=0;i<n;i++)
		bitmap[i] = (v[i] > threshold ? 1 : -1);
	
	//kadane's modified solution.
	int wellP=0,len=0,maxLen=0;
	for(int i=0;i<n;i++)
	{
		if(wellP + bitmap[i] >= 0)
		{
			wellP += bitmap[i];
			len++;
			if(len>maxLen)	maxLen = (wellP==0 ? len-1 : len);

		}
		else
		{
			wellP=0; len=0;
		}

	}
	cout<<maxLen<<endl;



/*output : 
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ g++ longest-well-perf-period.cpp -std=c++11
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
4
5 10 8 9
8
3
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
5
4 7 5 8 3
5
3
*/
