/*
Below is the bottom up implementation for Unbounded Knapsack(0-N Knapsack) .We are using 1D array.
A simple 1D array, say dp[W+1] can be used such that dp[i] stores the maximum value which can achieved
using all items and i capacity of knapsack. Note that we use 1D array here which is different from 
classical knapsack where we used 2D array. Here number of items never changes. We always have all items available.

We can recursively compute dp[] using below formula

dp[i] = 0
dp[i] = max(dp[i], dp[i-wt[j]] + val[j] 
                   where j varies from 0 
                   to n-1 such that:
                   wt[j] <= i

result = d[W]

for Input : W = 8
            val[] = {10, 40, 50, 70}
            wt[]  = {1, 3, 4, 5}  
  Output:
  Max value possible for knapSack capacity 0 is 0
  Max value possible for knapSack capacity 1 is 10
  Max value possible for knapSack capacity 2 is 20
  Max value possible for knapSack capacity 3 is 40
  Max value possible for knapSack capacity 4 is 50
  Max value possible for knapSack capacity 5 is 70
  Max value possible for knapSack capacity 6 is 80
  Max value possible for knapSack capacity 7 is 90
  Max value possible for knapSack capacity 8 is 110
  Final Max value obtained is 110


*/

#include <iostream>
#include <cstring> 
using namespace std;
int knapSack(int val[],int wt[],int W, int n) 
{ 
    int dp[W+1];
    memset(dp,0,sizeof dp); 
 
 for(int i=0;i<=W;i++)
 {
     for(int j=0;j<=n;j++)
    {
       if(wt[j]<=i)
        dp[i]= max(dp[i],val[j]+dp[i-wt[j]]);
       
     }
 }
  //printing the bottomUp array whose each index signifies the knapsack capacity and value
  //at that index has max value possible for that knapsack capacity
  for(int i=0;i<=W;i++)
  cout<<"Max value possible for knapSack capacity "<<i<<" is "<<dp[i]<<endl;

 return dp[W];
   
} 
int main() {
   int n,W;
  cin>>n;
  int val[n];
  int wt[n];
  for(int i=0;i<n;i++)
  {
      cin>>val[i];
  }
  for(int i=0;i<n;i++)
  {
      cin>>wt[i];
  }
  cin>>W;
 
  cout<<"Final Max value obtained is "<<knapSack(val,wt,W,n-1);
  return 0;
}
