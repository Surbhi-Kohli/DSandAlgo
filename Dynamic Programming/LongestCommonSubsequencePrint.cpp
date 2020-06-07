/*

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the
order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after
removal of elements C, E and F.

Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings
A and B, where LCS is the longest sequence present in both A and B.

Note: It is gauranteed that there is only one unique longest common subsequence

Input Format
Two strings A and B.

Constraints
1 <= n,m <= 10^3

Output Format
Output the LCS of A and B.

Sample Input
abc
acd
Sample Output
ac
*/
#include <bits/stdc++.h>
using namespace std;
void lcs(string X, string Y, int m, int n) 
{ 
   string ans="";
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
      dp[i][0]=0;
    
    for(int j=0;j<=n;j++)
    dp[0][j]=0;
    
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int q=0;
           if(X[i-1]==Y[j-1])
           {
              q=1+dp[i-1][j-1];
              
           }
            
           else
           q=max(dp[i-1][j],dp[i][j-1]);
           
           dp[i][j]=q;
           
       }
   }
   int i=m,j=n;
   //we start from bottom right corner and trace up..coz that is the path for LCS string
        while(i>=1 && j>=1)
       {
           if(X[i-1]==Y[j-1])//if chars in both strings is same in path,consider the chars
           {
                ans=X[i-1]+ans;
                i--;
                j--;
           }
          
           else if(dp[i][j-1]>dp[i-1][j])//else move in either direction
           {
               j--;
           }
           else
           i--;
           
       }
  
cout<<ans<<endl;//GTAB
 
} 
int main() {
    string s1,s2;
    cin>>s1>>s2;//"AGGTAB","GXTXAYB"
    int len1=s1.length();
    int len2=s2.length();
  
    lcs(s1,s2,len1,len2);
	return 0;
}
