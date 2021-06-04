#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    //n++;
	    int a[n];
	    //a[0] = 0;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    unordered_map<int,int> mp;
	    mp[0] = 1;
	    int preSum = 0,count = 0;
 	    for(int i=0;i<n;i++)
	    {
	        preSum += a[i];
	        count += mp[preSum];
	        mp[preSum]++;
	    }
	   
	    cout<<count<<endl;
	}
	return 0;
}
