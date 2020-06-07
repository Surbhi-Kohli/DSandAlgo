/*
Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

Input Format
First line contains first string . Second line contains second string. Third line contains the third string.

Constraints
The length of all strings is |s|< 200

Output Format
Output an integer denoting the length of longest common subsequence of above three strings.

Sample Input
GHQWNV
SJNSDGH
CPGMAH
Sample Output
2
Explanation
"GH" is the longest common subsequence

*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string X, string Y,string Z, int m, int n,int o) 
{ 
   string ans="";
    int dp[m+1][n+1][o+1];
    
 

   for(int i=0;i<=m;i++)
   {
       for(int j=0;j<=n;j++)
       {
           for(int k=0;k<=o;k++)
           {
             int q=0;
             if(i==0||j==0||k==0)
              dp[i][j][k]=0;
            else if(X[i-1]==Y[j-1] &&X[i-1]==Z[k-1])
             {
               q=1+dp[i-1][j-1][k-1];
             }
            
           else
           q=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
           
           dp[i][j][k]=q;
           }
       }
   }
    
 
    return dp[m][n][o];
   
} 
int main() {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    //cout<<s1<<endl;
    int len1=s1.length();
    int len2=s2.length();
    int len3=s3.length();
   // cout<<len3<<endl;
    cout<<lcs(s1,s2,s3,len1,len2,len3);
	return 0;
}
