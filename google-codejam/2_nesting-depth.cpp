#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,t;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        string a;
        cin>>a;
        a = '0'+a+'0';

        int n = a.size();
        vector<int> open(n-1),close(n-1);

        for(int i=1;i<n-1;i++)
        {
            int prev = a[i-1] - '0';
            int curr = a[i] - '0';
            int next = a[i+1] - '0';
            open[i] = curr-prev;
            close[i] = curr-next;

            if(open[i] < 0)     open[i] = 0;
            if(close[i] < 0)    close[i] = 0; 

        }
       
        string ans="";
        for(int i=1;i<n-1;i++)
        {
            string temp = to_string(a[i]-'0');
            temp.insert(temp.begin(),open[i],'(');
            temp.insert(temp.end(),close[i],')');
            ans += temp;

        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    
}
