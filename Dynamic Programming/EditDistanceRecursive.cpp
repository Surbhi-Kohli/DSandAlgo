/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

Examples:

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a

What are the subproblems in this case?
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

m: Length of str1 (first string)
n: Length of str2 (second string)
If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1

The time complexity of above solution is exponential. In worst case, we may end 
up doing O(3m) operations. The worst case happens when none of characters of two strings match.

*/

#include <iostream>
using namespace std;
int editDistance(string s1,string s2,int m,int n)
{   
    if(n==0)
    return m;
    
    if(m==0)
    return n;
    
    if(s1[m-1]==s2[n-1])
    return editDistance(s1,s2,m-1,n-1);
    
    return 1+min(min(editDistance(s1,s2,m-1,n-1),editDistance(s1,s2,m-1,n)),editDistance(s1,s2,m,n-1));
    
}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int m=s1.length();
  int n=s2.length();
  cout<<editDistance(s1,s2,m,n);

    return 0;
}
