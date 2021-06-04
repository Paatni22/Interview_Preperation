#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public static String solution(int ind) {
        // Your code here
        boolean[] sieve = new boolean[20000];
        int n = sieve.length;
        String str="";
        for(int i=2;i<n;i++)
        {
            if(sieve[i]==false){
                str+= Integer.toString(i);
                for(int j=i+i;j<n;j+=i)
                    sieve[j] = true;
            } 
        }
        System.out.println("size = "+str.length+"\n");
        String ans = substring(ind,ind+5);
    }
}


