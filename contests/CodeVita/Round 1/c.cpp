#include<iostream>
#include<set>
#include<vector>

using namespace std;
int vowelsIn(string str)
{
	int ans = 0,n = str.length();

	for(int i=0;i<n;i++)
	{
		char ch = str[i];
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			ans++;
	}
	cout<<str<<" n = "<<n<<" ans = "<<ans<<endl;
	return ans;
}
int main()
{

	string text_rep[] = {"zero", "one", "two", "three", "four", "five",  "six", "seven",  "eight",  "nine",
 "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
"seventeen", "eighteen", "nineteen", "twenty", "twentyone",  "twentytwo", 
"twentythree", "twentyfour", "twentyfive", "twentysix", "twentyseven", 
"twentyeight", "twentynine",  "thirty", "thirtyone",  "thirtytwo","thirtythree", 
"thirtyfour", "thirtyfive", "thirtysix", "thirtyseven", "thirtyeight",  "thirtynine", 
"forty", "fortyone", "fortytwo", "fortythree", "fortyfour",  "fortyfive", "fortysix",
 "fortyseven", "fortyeight", "fortynine", "fifty", "fiftyone",  "fiftytwo", 
"fiftythree", "fiftyfour", "fiftyfive", "fiftysix", "fiftyseven", "fiftyeight",  "fiftynine",
 "sixty", "sixtyone", "sixtytwo", "sixtythree", "sixtyfour", "sixtyfive",  "sixtysix",
 "sixtyseven", "sixtyeight", "sixtynine", "seventy", "seventyone",  "seventytwo",
 "seventythree", "seventyfour","seventyfive", "seventysix", "seventyseven", 
"seventyeight", "seventynine",  "eighty", "eightyone", "eightytwo",  "eightythree", 
"eightyfour", "eightyfive",  "eightysix",  "eightyseven", "eightyeight",  "eightynine", 
"ninety", "ninetyone",  "ninetytwo",  "ninetythree", "ninetyfour", "ninetyfive", 
"ninetysix", "ninetyseven",  "ninetyeight", "ninetynine", "hundred"};

	
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int index=0;index<n;index++)
		cin>>a[index];
	int X = 0;
	string str;
	for(int index=0;index<n;index++)
	{
		str = text_rep[a[index]];
		X += vowelsIn(str);
	}
	// X is done
	cout<<"x = "<<X<<endl;
	//sort(a.begin(),a.end());
	/*int lb = 0,ub = n-1, ans = 0;
	set<pair<int,int> > st;
	while(lb<ub)
	{
		if(X == a[lb]+a[ub])
		{
			ans++;//cout<<a[lb]<<" "<<a[ub]<<endl;
			//st.insert(make_pair(a[lb],a[ub]));
			lb++;
		}
		else if(X > a[lb]+a[ub])
			lb++;
		else
			ub--;
	}*/
	int ans;
	set<int> st;
	for(int i=0;i<n;i++)
	{
		int diff = X - a[i];
		if(st.find(diff) != st.end())	ans++;
		st.insert(a[i]);
	}
	//ans = st.size();
	if(ans > 100)	cout<<"greater 100";
	else
		cout<<text_rep[ans];

}