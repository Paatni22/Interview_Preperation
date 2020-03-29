#include <bits/stdc++.h>
#include<vector>
#include<cmath>

using namespace std;

void Inorder( map<int,vector<int>> &mp, vector<int> &a,vector<int> &b,vector<int> &c,int i)
{
    
    a.push_back(i);
    if(mp.count(i)!=0 && mp[i].size() >0)
        Inorder(mp,a,b,c,mp[i][0]);
    b.push_back(i);
    if(mp.count(i)!=0 && mp[i].size()==2)
        Inorder(mp,a,b,c,mp[i][1]);
    c.push_back(i);

}

int median(int a,int b,int c)
{
    vector<int> v{a,b,c};
    sort(v.begin(),v.end());
    
    return v[1];
   
}

int main()
{
    int m;
    cin>>m;
    map<int,vector<int>> mp;
    int node = 1;
    int parent;
    int temp = m;
    while(temp--)
    {
        cin>> parent;
        mp[parent].push_back(node);
       
        node++;
    }
    vector<int> a,b,c;
   Inorder(mp,a,b,c,0);
  
 
   int ans = 0;
  
   for(int i=0;i<=m;i++)
   {
    ans += median(a[i],b[i],c[i]);
    
   }
   cout<<ans<<endl;
    
}
/*
input : 
6
0 0 1 2 3 1
output : 
24
input : 
2
0 0
output : 
4
*/
