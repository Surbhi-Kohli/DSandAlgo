#include<bits/stdc++.h>
using namespace std;
bool compare(string s1 ,string s2)
{
    if(s1.length()==s2.length())
      return s1>s2; //if lengths of the 2 strings are equal,order should be in lexicographically descending order
                     //ie if s1 ="ab" and s2="cd"  order= cd, ab
    else
    return s1.length()<s2.length();//else sorted in descending order of length
   
}
int main() {

    string a[]={"ab","aab","cccddd","cd","xxy","z"};
    int n=6;
    
   
    sort(a,a+n,compare);
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<" ";
    }
	return 0;
}
