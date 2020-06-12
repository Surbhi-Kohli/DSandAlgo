/*
Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate
maximum value with weight being within the knapsack capacity. This is different from classical Knapsack problem, 
here we are allowed to use unlimited number of instances of an item.The problem has optimal substructure problem
as optimal answer for knapsack capacity 1kg gives optimal answer for knapsack capacity 2kg  .

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.

For the above output we get the following output
We can see that values get recomputed when we follow recursion
output
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 4 is 50
value when W is 1 is 10
value when W is 2 is 20
value when W is 1 is 10
value when W is 5 is 70
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 2 is 20
value when W is 1 is 10
value when W is 6 is 80
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 4 is 50
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 2 is 20
value when W is 7 is 90
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 4 is 50
value when W is 1 is 10
value when W is 2 is 20
value when W is 1 is 10
value when W is 5 is 70
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 1 is 10
value when W is 4 is 50
value when W is 1 is 10
value when W is 2 is 20
value when W is 3 is 40
value when W is 8 is 110
Max value obtained is 110
*/

#include <iostream>
using namespace std;
int knapSack(int val[],int wt[],int W, int n) 
{ 
   //int dp[W+1];
   //memset(dp,0,sizeof dp);
 
  if(W==0)
  return 0;
  int ans=0;
  for(int i=0;i<=n;i++)
 {
    if(wt[i]<=W)
    ans= max(ans,val[i]+knapSack(val,wt,W-wt[i],n));
 }
 cout<<"value when W is "<<W<<" is "<<ans<<endl;
 return ans;
   
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
  
       
  cout<<"Max value obtained is "<<knapSack(val,wt,W,n-1);
  return 0;
}
