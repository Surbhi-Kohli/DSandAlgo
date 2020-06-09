/*

This method uses Memoization Technique (an extension of recursive approach).

This method is basically an extension to the recursive approach so that we can overcome the problem of 
calculating redundant cases and thus increased complexity. We can solve this problem by simply creating a
2-D array that can store a particular state (n, w) if we get it the first time. Now if we come across the 
same state (n, w) again instead of calculating it in exponential complexity we can directly return its result 
stored in the table in constant time. This method gives an edge over the recursive approach in this aspect.

Time Complexity: O(N*W).
As redundant calculations of states are avoided.
Auxiliary Space: O(N*W).
The use of 2D array data structure for storing intermediate states
*/
#include <iostream>
using namespace std;
int knapSack(int val[],int wt[],int W,int **dp,int index)
{  
    if(index<0)
    return 0;

    if(dp[index][W]!=-1)
    return dp[index][W];
     if(wt[index-1]>W)
     dp[index][W]=knapSack(val,wt,W,dp,index-1);

     else{
         dp[index][W]=max(knapSack(val,wt,W,dp,index-1),val[index-1]+knapSack(val,wt,W-wt[index-1],dp,index-1));
     }
  return dp[index][W];
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
  //we build a dp table which will be filled top down.
  //the dimensions of table are (n+1)*(W+1)
  //where rows-0 to n signify the index of picked item,so row 0 means no item is picked,
  //row 1 means item at index 0 in val array iis picked
  //columns 0 to W+1 means weight of knapsack filled ,column 0 means,the knapsack has 0 weight currently n
  //column W+1 means knapsack has things that weigh W
  int **dp;
  dp=new int*[n+1];
    for (int i = 0; i <= n; i++) 
        dp[i] = new int[W + 1]; 

        for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= W; j++) 
            dp[i][j] = -1;   
  cout<<knapSack(val,wt,W,dp,n);
  return 0;
}
