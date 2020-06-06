/*
Given two strings s1 and s2, the task is to find the length of longest common subsequence present in both of them.

Examples:
Input: s1 = “ABCDGH”, s2 = “AEDFHR”
Output: 3
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
Input: s1 = “striver”, s2 = “raj”
Output: 1

The naive solution for this problem is to generate all subsequences of both given sequences and find the 
longest matching subsequence. This solution is exponential in term of time complexity. The general recursive solution 
of the problem is to generate all subsequences of both given sequences and find the longest matching subsequence. 
Total possible combinations will be 2n. Hence recursive solution will take O(2n).

*/

#include <iostream>
using namespace std;
int lcs(string s1,string s2,int i,int j,int n,int m)
{
    if(i==n||j==m)
    return 0;
    if(s1[i]==s2[j])
    return 1+lcs(s1,s2,i+1,j+1,n,m);
    
    else 
    return max(lcs(s1,s2,i+1,j,n,m),lcs(s1,s2,i,j+1,n,m));
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
   // int dp[100][100];
    
    cout<<lcs(s1,s2,0,0,n,m);
	// your code goes here
	return 0;
}
