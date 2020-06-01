/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 
8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two 
pieces of lengths 2 and 6)
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20


And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20


*/
#include <iostream>
#include <climits>
using namespace std;
int maxProfitRodCutting(int lenCost[],int n,int dp[])
{
    if(n==0)
    return 0;
    int best=0;
    if(dp[n]!=0)
    return dp[n];
    
    for(int i=0;i<n;i++)
    {
        int curr_profit=lenCost[i]+maxProfitRodCutting(lenCost,n-i-1,dp);
        best=max(best,curr_profit);
    }
    dp[n]=best;
return  dp[n];
}
int main() {
	
	int lenCost[]= {1, 5, 8, 9, 10, 17, 17, 20};
	int n=8;
	int dp[100]={0};
  cout<<maxProfitRodCutting(lenCost,n,dp);
	return 0;
}
