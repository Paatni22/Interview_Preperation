/*
Q. WAP to print possibilities for choosing an ordered set of
 r objects (a permutation) from a total of n objects.

  Note : repetition is not allowed.

*/
#include <bits/stdc++.h> 
#define pb push_back
#define pob pop_back
#include "class.cpp"
using namespace std; 

int main()
{
    vector<int> v{1,2,2};
    vector<vector<int>> ans;
    Solution ob;
    ans = ob.subsetsWithDup(v);    

    for(auto &x:ans) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
   
}


