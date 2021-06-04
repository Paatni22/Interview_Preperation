#include <iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

void split(string str,char delimeter,vector<string> &octets)
{
	int n = str.length();
	string temp="";
	for(int i=0;i<n;i++)
	{
		if(str[i] != delimeter)
		{
			temp += str[i];
		}
		else
		{
			octets.push_back(temp);
			temp = "";
		}
	}
	if(temp!= "")
		octets.push_back(temp);

}
string binary(int no)
{
	string ans = "";
	while(no)
	{
		int last_bit = no&1;
		ans = to_string(last_bit) + ans;
		no = no>>1;
	}
	return ans;
}
int main()
{
	string inp;
	cin>>inp;	//input ip addr in decimal
	vector<string> octets;
	split(inp,'.',octets);

	string ans = "";
	for(auto x:octets)
	{
		int no = stoi(x);
		string bin = binary(no);

		stringstream sout;
		sout<<setw(8)<<setfill('0')<<bin;

		ans += (sout.str()+".");
	}
	ans.pop_back();
	cout<<ans<<endl;
}
/*
surajpatni@s:~/Documents/Interview_Preperation/basic-codes$ g++ ip_decimal_to_binary.cpp  -std=c++11
surajpatni@s:~/Documents/Interview_Preperation/basic-codes$ ./a.out
32.64.128.255
00100000.01000000.10000000.11111111

*/