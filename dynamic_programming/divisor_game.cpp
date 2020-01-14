// https://leetcode.com/problems/divisor-game/submissions/

class Solution {
public:
int No;
vector<vector<int>> dp;
bool IsWin(int no,int turn)
{
    if(dp[no][turn] != -1)  return dp[no][turn];
    
	if(no==1)
	{
		if(turn==0) // my turn
			return false;
		else
			return true;
	}
	bool ans = false;
	for(int i=1;i<no;i++)
	{
		if(No%i !=0)	continue;
		ans = ans || IsWin(no-i,1-turn);
	}
	return dp[no][turn] = ans;
}
    bool divisorGame(int N) {
        dp.resize(N+1,vector<int>(2,-1));
        No = N;
        return IsWin(N,0);
    }
};