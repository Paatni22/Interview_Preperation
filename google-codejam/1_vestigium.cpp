#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,t;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(n));

        map<int,set<int>> row;
        map<int,set<int>> col;

        for(auto &x:a)
            for(auto &y:x)
                cin>>y;
        int k=0,r=0,c=0;    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    k+=a[i][j];
                row[i].insert(a[i][j]);
                col[j].insert(a[i][j]);

            }
        } 
        for(int i=0;i<n;i++)
        {
        
            if(row[i].size() < n)   r++;
            if(col[i].size() < n)   c++; 
  
        } 
        cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    
}
