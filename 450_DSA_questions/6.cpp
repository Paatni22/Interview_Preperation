// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
#include<bits/stdc++.h>
using namespace std;

void UnionAndInt(int a[], int n, int b[], int m)  {
    //code 
    int ans=0;
    int mapa[100000] = {0};
    int mapb[100000] = {0};
    vector<int> un;
    vector<int> in;
    for(int i=0;i<n;i++)
    {
        if(mapa[a[i]] == 0 )
        {
            un.push_back(a[i]);
            mapa[a[i]] = 1;
        }

    }
    for(int i=0;i<m;i++)
    {
        if(mapa[b[i]] == 0 && mapb[b[i]] == 0 )
        {
            un.push_back(b[i]);
            mapb[b[i]] = 1;
        }
        else if(mapa[b[i]] == 1)
            in.push_back(b[i]);

    }
    cout<<"union: ";
    for(int i=0;i<un.size();i++)
    {
        cout<<un[i]<<" ";
    }
    cout<<endl<<"interesection: ";
    for(int i=0;i<in.size();i++)
        cout<<in[i]<<" ";
    cout<<endl;
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    UnionAndInt(a,n,b,m);
}