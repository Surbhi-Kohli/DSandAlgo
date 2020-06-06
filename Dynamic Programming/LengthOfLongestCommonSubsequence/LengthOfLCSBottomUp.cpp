/*
Time Complexity of the above implementation is O(mn) which is much better than the worst-case
time complexity of Naive Recursive implementation.
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string X, string Y, int m, int n) 
{ 
   
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
      dp[i][0]=0;
    //cout<<"row initialization done"<<endl;
    for(int j=0;j<=n;j++)
    dp[0][j]=0;
    
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int q=0;
           if(X[i-1]==Y[j-1])
             q=1+dp[i-1][j-1];
           else
           q=max(dp[i-1][j],dp[i][j-1]);
           
           dp[i][j]=q;
           
       }
   }

  return dp[m][n];
   
} 
int main() {
    string s1,s2;
    cin>>s1>>s2;
    //cout<<s1<<endl;
    int len1=s1.length();
    int len2=s2.length();
  
    cout<<lcs(s1,s2,len1,len2);
	return 0;
}
