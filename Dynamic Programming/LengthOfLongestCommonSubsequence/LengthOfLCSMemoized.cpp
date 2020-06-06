/*
Given two strings s1 and s2, the task is to find the length of longest common subsequence present in both of them.
Time Complexity: O(N * M), where N and M is length of the first and second string respectively.
Auxiliary Space: (N * M)
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string X, string Y, int m, int n, int dp[100][100]) 
{ 
    // base case 
    if (m == 0 || n == 0) 
        return 0; 
  
    // if the same state has already been 
    // computed 
    if (dp[m - 1][n - 1] != -1) 
        return dp[m - 1][n - 1]; 
  
    // if equal, then we store the value of the 
    // function call 
    if (X[m - 1] == Y[n - 1]) { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1, dp); //for this statement,our string indexes start from 1,1
  
    } 
    else { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = max(lcs(X, Y, m, n - 1, dp), 
                               lcs(X, Y, m - 1, n, dp)); 
  
        
    } 
    return dp[m - 1][n - 1]; 
} 
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.length();
    int len2=s2.length();
   int dp[100][100];
   
    memset(dp, -1, sizeof(dp)); 
    cout<<lcs(s1,s2,len1,len2,dp);
	return 0;
}
