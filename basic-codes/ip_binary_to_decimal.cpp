#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void getOctetsInIntegers(string str,vector<int> &octets)
{
	int n = str.size(),i;
	i = n-1;
	int temp = 0,weight=1;
	while(i>=0)
	{
		if(str[i] == '.')
		{
			weight = 1;
			octets.push_back(temp);
			temp = 0;
		}
		else
		{
			temp += weight*(str[i]-'0');
			weight *= 2;
		}
		i--;
	}
	octets.push_back(temp);
	reverse(octets.begin(),octets.end());
}

// input should have 4 octets of 8 bits.
int main()
{
	string inp;
	cin>>inp;	//enter ip in binary

	vector<int> octets;

	getOctetsInIntegers(inp,octets);

	string ans = "";
	for(auto x:octets)
	{
		ans += to_string(x)+".";
	}
	ans.pop_back();
	cout<<ans<<endl;
}
/*
surajpatni@s:~/Documents/Interview_Preperation/basic-codes$ g++ ip_binary_to_decimal.cpp -std=c++11
surajpatni@s:~/Documents/Interview_Preperation/basic-codes$ ./a.out
10000000.00000000.01000000.00100000
128.0.64.32
*/