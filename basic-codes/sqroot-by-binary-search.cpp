// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
#include <bits/stdc++.h>
#define nullptr NULL

using namespace std;



int main()
{
    vector<int> a{4,9,25,1,64,65};
    int n = a.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    {
        int no = a[i];
        int lb=0,ub=no/2;
        while(lb<=ub)
        {
            int mid = (lb+ub)/2;
            if(mid*mid == no)
            {   ans[i] = mid;break;}
            else if(mid*mid < no)
                lb = mid+1;
            else    ub = mid-1;


        }


        cout<<a[i]<<"  "<<ans[i]<<endl;
    }
   

}
