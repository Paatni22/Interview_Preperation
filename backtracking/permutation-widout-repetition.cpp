/*
Q. WAP to print possibilities for choosing an ordered set of
 r objects (a permutation) from a total of n objects.

  Note : repetition is not allowed.

*/
#include <bits/stdc++.h> 
#define pb push_back
#define pob pop_back
using namespace std; 
void combinations(string s,int r,vector<char> &curr,vector<vector<char>> &result)
{
	int n = s.size();
	if(curr.size() == r)	{
		result.pb(curr);	return;
	}
	for(int i=0;i<n;i++)
	{
		curr.pb(s[i]);

		string temp = s;     // only change to avoid repetition. 
		temp.erase(i,1);	// only change to avoid repetition.

		combinations(temp,r,curr,result);
		curr.pop_back();
	}
}

int main()
    {
    	
    	string s = "abc";
    	int r = 2;
    	vector<vector<char>> result;
    	vector<char> curr;
    	combinations(s,r,curr,result);

    	for(auto &v:result)
    	{
    		for(auto ch:v)
    			cout<<ch;
    		cout<<endl;
    	}

    	
    


    }






