/*
3. Longest Substring Without Repeating Characters
Q.Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Input: "abba"
Output: 2
*/
class Solution {
public:
	int max(int a,int b)
	{
		return (a>b?a:b);
	}
    int lengthOfLongestSubstring(string s) {
        map<char,int> lastIndexOf;
        int n = s.size();

        // By sliding window.

        int i=0;
        int ans = 0;
        for(int j=0;j<n;j++)
        {
        	if(lastIndexOf.count(s[j]) )
        	{
        		i = max(i , lastIndexOf[s[j]]+1);  
        	}

        	lastIndexOf[s[j]] = j;

        	int currLen = j-i+1;
        	ans = max(ans,currLen);

        }



        
        /*
        By my method used map though.
        int ans=0,currLen=0;
        for(int i=0;i<n;i++)
        {
            if(lastIndexOf.count(s[i]))
            {
                currLen = min(i - lastIndexOf[s[i]],currLen+1);
            }
            else
                currLen++;
            lastIndexOf[s[i]] = i;
            
            if(ans < currLen)   ans = currLen;
        }
        */

        return ans;
    }
};