class Solution {
public:
    
	int dec(vector<int> a,int lb,int ub)
	{
		int ans = 0;
		for(int i=lb;i<=ub;i++)
			ans = ans*2 + a[i];
		return ans;
	}
	string timeOf(vector<int> a)
	{
		int hr = dec(a,0,3);
		int min = dec(a,4,9);
    
        if(hr > 11 || min > 59 ) return "invalid";
        
		string h,m;
		ostringstream sout;
		h = to_string(hr);
        
		sout<< setw(2)<<setfill('0')<<min;
		m = sout.str();
        
        

		return h+ ":"+m;
		//sprin

	}
	void poss(vector<int> &dw,int i,int n,vector<string> &ans)
	{
		if(n==0)
		{
            string time = timeOf(dw);
            if(time=="invalid") return;
			ans.push_back( time );
			return;
		}
		if(i==-1)	return;	// or cond. can be: if(i+1 < n) 

		poss(dw,i-1,n,ans);
		dw[i] = 1;
		poss(dw,i-1,n-1,ans);
		dw[i] = 0;
	}
	vector<string> readBinaryWatch(int m) {
		int n=10; 
		vector<string> ans;
		vector<int> dw(n,0);
		poss(dw,n-1,m,ans); 
       // reverse(ans.begin(),ans.end());
        return ans;
    }

};