#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,limit;
        cin>>n>>limit;
        vector<int> v(n);
        for(auto &x:v)
            cin>>x;
        sort(v.begin(),v.end(),greater<int>());
        if(v[0] > limit){
            cout<<"impossible"<<endl; continue;
        }
        int ans = 1,i=0;
        while(v[i] + v[i+1] > limit)
        {
            ans++; i++;
        }
           
        cout<<ans<<endl;
    }
}




