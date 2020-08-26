/*
Rearrange characters : 


https://practice.geeksforgeeks.org/problems/rearrange-characters/0

Given a string S with repeated characters (only lowercase).
The task is to rearrange characters in a string such that no 
two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

 
 aabb -> abab  yes
 aaab -> abaa  no


 abc abc aaaaa  ->   abac abac aa.

 a - 7 , b - 2, c -2.

  a b a c a b a c a


  maxfreq restfreq.
  maxfreq > restfreq+1  -> no
  else yes.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		int n = str.size();
		map<char,int> mp;
		for(auto ch:str)
			mp[ch]++;

		int maxFreq = 0;
		for(auto x: mp)
		{
			if(x.second > maxFreq)
				maxFreq = x.second;
		}
		int restFreq = n - maxFreq;

		if(maxFreq > restFreq+1)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;

	}
}


