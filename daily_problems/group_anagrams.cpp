// https://practice.geeksforgeeks.org/problems/k-anagrams-1/0
/*
Given an array of words, print the count of all anagrams together 
in sorted order (increasing order of counts).
For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”},
then grouped anagrams are “(dog, god) (cat, tac, act)”. 
So the output will be 2 3.
*/
#include <bits/stdc++.h>
using namespace std;
string mask_string(string str)
{
    string mask(26,'0');
    for(char ch:str)
        mask[ch-'a']++;
    return mask;
}
// mask will be like:
//"abc" ->  "1110000000000..."
//"ce"   -> "0010100000....."

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    //input
	    int n;
	    cin>>n;
	    vector<string> a(n);
	    for(auto &x:a)
	        cin>>x;
	    
	    // code
	    map<string,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        string mask = mask_string(a[i]);
	        mp[mask]++;
	    }
	    // O(n*k)
	    //sort and output
	    vector<int> ans;
	    for(auto x:mp)
	        ans.push_back(x.second);
	    sort(ans.begin(),ans.end());
	    for(auto x:ans)
	        cout<<x<<" ";
	    cout<<endl;
	    
	}
	return 0;
}
