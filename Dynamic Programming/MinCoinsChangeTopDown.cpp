/*
Find minimum number of coins that make a given value
Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued 
coins, what is the minimum number of coins to make the change?

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
U might think of greedy approach,but that won't work .Consider the following scenario
n=15 n coins=[1,7,10]
with greedy approach  15-10=5 ; coins used=10
                       5-1=4  ; coins used=10,1
                       4-1=3  ; coins used=10,1,1
                       3-1=2  ; coins used=10,1,1,1
                       2-1=1  ; coins used=10,1,1,1,1
                       1-1=0  ; coins used=10,1,1,1,1,1= 6 coins in total
              But best answer would be 7,7,1=3 coins
 Best way to verify whether greedy will work or not is by making a counter test case,where greedy fails.
 We don't know what is the best posible way to make the changes ,so we'll try out all possible options i.e recursion.
 And we will add DP to it.Dynamic Programming is basically an optimmisation to recursive formulation
              
*/
#include <iostream>
#include <climits>
using namespace std;
int minCoins(int n,int coins[],int T,int dp[])
{
    //base case
    if(n==0)
    return 0;
    
    if(dp[n]!=0)
    return dp[n];
    
    int ans=INT_MAX;
    
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)
        {
            int subprob=minCoins(n-coins[i],coins,T,dp);
            ans=min(ans,subprob+1);
        }
    }
    dp[n]=ans;
    return dp[n];
}
int main()
{
 
   int n=15;
   int coins[]={1,7,10};
   int dp[100]={0};
   int T=sizeof(coins)/sizeof(int);
   cout<<minCoins(n,coins,T,dp);
   return 0;
}

