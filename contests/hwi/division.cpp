#include <bits/stdc++.h>
#include<vector>
#include<cmath>
#include<limits.h>
  using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long divisor,rem,N,ans = -1;
        cin >> divisor >> rem >> N;


        int no = (N-1)/divisor * divisor + rem;
        if(rem  >= divisor)  ans = -1;
        else if(no <= N) ans = no;
        else
        {
            no = no - divisor;
            if(no<0)    ans = -1;
            else    ans = no;
        }
        cout<<ans<<endl;
        
    }
    
}
