#include <iostream>
#include <cstring> 
using namespace std;
int knapSack(int val[],int wt[],int W, int n,int dp[]) 
{ 
  if(W==0)
  return 0;
  if(dp[W]!=0)
  return dp[W];
  int ans=0;
  for(int i=0;i<=n;i++)
 {
    if(wt[i]<=W)
    ans= max(ans,val[i]+knapSack(val,wt,W-wt[i],n,dp));
 }

 dp[W]=ans;
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
  int dp[W+1];
      memset(dp,0,sizeof dp); 
  cout<<"Max value obtained is "<<knapSack(val,wt,W,n-1,dp);
  return 0;
}
