/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
#include<iostream>
#include<vector>
#define MAX 1000000
#define MAX_N 100000
using namespace std;

// Write your code here
int main()
{
    vector<int> primeCount(MAX_N,-1);
    primeCount[0] = primeCount[1] = 0;
    for(int i=2;i<=MAX_N;i++)
    {
        if(primeCount[i] == -1)  //prime no.
        {
            primeCount[i] = primeCount[i-1]+1;
            for(int j=i+i;j<=MAX_N;j+=i)
            {
                primeCount[j] = 0;
            }
        } 
        else
            primeCount[i] = primeCount[i-1];
    }
     for(int i=0;i<10;i++)
        {
            cout<<primeCount[i]<<",";
        }cout<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int r1,r2,n;
        cin>>r1>>r2;cin>>n;
        string block;
        //getchar();    //  optional
        cin>>block;

        vector<float> val(n+1);
        vector<bool> special(n+1);
        for(int i=1;i<=n;i++)
        {
            val[i] = (float)primeCount[i]/i;
            if(val[i] >= (float)r1/r2)  special[i] = true;
            else    special[i] = false;
        }
        vector<int> dp(n+1);
        dp[n] = 0;
        // for(auto x:special)
        // {
        //     cout<<x<<",";
        // }cout<<endl;
        
        for(int i=n-1;i>=1;i--)
        {
            if(block[i] == '*'){    dp[i] = MAX ; continue;}
            int step = primeCount[i];
            dp[i] = min( (i+1>n ? MAX : dp[i+1]),(i+1>n ? MAX : dp[i+2]));
            if(special[i] && i+step <= n)
                dp[i] = min(dp[i] , (i+step>n? MAX : dp[i+step]) );
            dp[i] += 1;
        }
        if(dp[1] >= MAX)
            cout<<"No way!"<<endl;
        else
            cout<<dp[1]<<endl;
        
        
    }
}