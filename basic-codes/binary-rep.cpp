#include <iostream>
#include<stack>
using namespace std;

void binary(int n,stack<int> &v)
{
    while(n)
    {
        v.push(n&1);
        n = n>>1;

    }
} 

int main() {
    // your code goes here
    int n;
    cin>>n;
    stack<int> bin;
    binary(n,bin);
    while(!bin.empty())
    {

        cout<<bin.top();
        bin.pop();
    }
    cout<<endl;
    return 0;
}
