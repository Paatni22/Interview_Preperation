#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void split(string s,char del,vector<string> &words)
    {
        int n = s.size();
        string currstr = "";
        for(int i=0;i<n;i++)
        {
            if(s[i] == del)
            {
                if(currstr!="") words.push_back(currstr);
                currstr="";
            }
            else
            {
                currstr += s[i];
            }
        }
        if(currstr!="") words.push_back(currstr);
    }
    string reverse(string str)
    {
        int n = str.size();
        for(int i=0;i<n/2;i++)
        {
            char temp = str[i];
            str[i] = str[n-i-1];
            str[n-i-1] = str[i];
        }
    }
    void reverseWordsOfVector(vector<string> &words)
    {
        int n = words.size();
        cout<<"size of vecor of words: "<<n<<endl;
        for(int i=0;i<n;i++)
        {
        cout<<words[i]<<" = ";
        string str = words[i];
            words[i] = reverse(str);
            cout<<words[i]<<endl;
        }
    }
    void mergeWords(vector<string> &words,char del,string &ans)
    {
        int n = words.size();
        for(int i=0;i<n-2;i++)
        {
            ans += words[i] + ".";
        }
        ans += words[n-1];
    }
    string reverseWords (string s)
    {
        //code here.
        char delimeter = '.';
        vector<string> words;
        split(s,delimeter,words);
        string ans;
        
        int n = words.size();
        reverseWordsOfVector(words);
/*        for(int i=0;i<n;i++)
        	cout<<words[i]<<" - ";
        cout<<endl;
/*
        mergeWords(words,delimeter,ans);*/
        return ans;
    }
};

int main()
{
	string s;
	cin>>s;
	Solution ob;
	cout<<endl<<ob.reverseWords(s)<<endl;
	return 0;
}





























