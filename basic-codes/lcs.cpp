
#include<bits/stdc++.h>
using namespace std;

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

    int na = a.size(), nb = b.size();
    vector<vector<int>> lcs(na+1,vector<int>(nb+1,0));
    vector<vector<vector<int> >> str(na+1,vector<vector<int> >(nb+1));
    for(int i=1;i<=na;i++)
    {
        for(int j=1;j<=nb;j++)
        {
            if(a[i-1] == b[j-1])
            {
                lcs[i][j] = 1+lcs[i-1][j-1];
                str[i][j] = str[i-1][j-1];
                //cout<<"pushing"<<a[i-1]<<"at"<<i<<j<<endl;
                str[i][j].push_back(a[i-1]);
            }
            else if(lcs[i-1][j] > lcs[i][j-1])
            {
                lcs[i][j] = lcs[i-1][j];
                str[i][j] = str[i-1][j];
            }
            else
            {
                 lcs[i][j] = lcs[i][j-1];
                str[i][j] = str[i][j-1];
            }
        }
       
        
    }
    
    vector<int> ans = str[na][nb];
    cout<<"ans=";
    for(int x: ans)
        cout<<x;
    cout<<endl;
    // for(int i=1;i<=na;i++)
    // {
    //     for(int j=1;j<=nb;j++)
    //     {
    //         vector<int> a = str[i][j];
    //         if(a.size()==0) cout<<"**\t";
    //         else
    //         {
    //             for(auto x:a)
    //                 cout<<x;
    //             cout<<"\t";
    //         }
    //     }
    //     cout<<endl;
    // }
    return ans;
     
    // vector<int> ans;
    
        // return ans;
}
int main() {

    vector<int> b{1,2,3,4};
    vector<int> a{4,2,1,3};
    vector<int> ans = longestCommonSubsequence(a,b);

}
/*
surajpatni@s:~/Documents/Interview_Preperation/practice$ g++ prac.cpp
surajpatni@s:~/Documents/Interview_Preperation/practice$ ./a.out
72
3surajpatni@s:~/Documents/Interview_Preperation/practice$ ./a.out
20
3
*/