#include<bits/stdc++.h>
using namespace std;
void toh(char source, char target, char aux, int n)
{
	if(n==1)
	{
		cout<<"transfer plate no: "<<n<<" from rod : "<<source<<" to : "<<target<<endl;
		return;
	}
	toh(source,aux,target,n-1);
	cout<<"transfer plate no: "<<n<<" from rod : "<<source<<" to : "<<target<<endl;
	toh(aux,target,source,n-1);

}
int main()
{
	int n;
	cout<<"enter the no. of rods: ";
	cin>>n;
	toh('A','C','B',n);
}