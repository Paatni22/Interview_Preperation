

#include <bits/stdc++.h>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v)
        cin>>x;

    map<int,int> mp;
    for(auto x: v )
        mp[x]++;
    auto it = mp.begin();

    int frequent,maxfreq=0;
    for(auto x:mp)
    {
        if(x.second > maxfreq)
        {
            maxfreq = x.second;
            frequent = x.first;
        }

    }
   
    int firstPos,lastPos;
    bool counted = false;
    int len = 0,maxLen = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i] == frequent)
        {
            if(!len)
            {
               
                if(maxLen < len)    maxLen = len;
                len = 0;
            }

            if(!counted){   counted = true;  firstPos = i;}    
            lastPos = i;
        }
        else
            len++;    
    }
    int temp = v.size()-1-lastPos + firstPos-0;

    //cout<<endl;
    //cout<<"temp = "<<temp<<endl;
    //cout<<"frequent = "<<frequent<<endl;

    maxLen = max(maxLen,temp);

    cout<<(maxLen+1)/2<<endl;
}

/*
test cases : 
4
1 1 2 2
1
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
5
1 1 2 2 2
1
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
6
1 1 1 2 2 2
2
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
9
0 0 1 2 1 5 1 2 2
2
surajpatni@s:~/Documents/Interview_Preperation/prev-year-questions/hack-with-infy$ ./a.out
10                       
2 2 1 3 1 4 1 3 4 5
3
*/

