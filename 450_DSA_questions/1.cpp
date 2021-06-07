//  https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

//User function Template for C++

void swap(char &a,char &b)
{
  char temp = a;
  a = b;
  b = temp;
}
string reverseWord(string str){
    
  //Your code here
  int n = str.size();
  for(int i=0,j=n-1; i<j; i++,j--)
  {
      swap(str[i],str[j]);
  }
  return str;
    
}

