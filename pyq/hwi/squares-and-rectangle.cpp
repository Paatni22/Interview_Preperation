#include <bits/stdc++.h>
#include<vector>
#include<cmath>

using namespace std;
bool rev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
int helper(vector<pair<int,int> > &v)
{
    int n = v.size();
    for(int i=0;i<n;i++)
        {
            cin>>v[i].first >> v[i].second;
        }
        sort(v.begin(),v.end(),rev);
        int prev=0,prevlen=0,ans=0;

        for(int i=0;i<v.size();i++)
        {
            int len = v[i].first,freq = v[i].second;

            if(freq>=4)
            {
                ans += 4*len;
                //cout<<"adding 4 "<<4*len<<endl;
            }
            int rem = freq%4;
            if(rem<2)   continue;
            if(prev>=2)
            {
                ans += 2*(prevlen+len);
                prev = prevlen = 0;
                //cout<<"adding 2 "<<2*(prevlen+len)<<endl;
            }
            else
            {
                prev = freq;
                prevlen = len;

            }
        }
        cout<< ans;
}

int main()
{
    

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > v(n);
        return helper(v);
    }
    
}