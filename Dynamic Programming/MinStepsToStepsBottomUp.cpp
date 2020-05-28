/*
Given a number n, count minimum steps to minimize it to 1 according to the following criteria:

If n is divisible by 2 then we may reduce n to n/2.
If n is divisible by 3 then you may reduce n to n/3.
Decrement n by 1.


*/
#include <iostream>
#include <climits>
using namespace std;
int minStepsToOne(int n)
{
    int dp[100]={0};
     int op1,op2,op3;
     
    
   for(int i=2;i<=n;i++)
   {
        op1=op2=op3=INT_MAX;
        
    if(n%3==0)
    {
        op1=dp[i/3]+1;
    }
    if(n%2==0)
    {
        op2=dp[i/2]+1;
    }
    op3=dp[i-1]+1;
    int ans=min(min(op1,op2),op3);
    dp[i]=ans;
   }
  return dp[n]; 
   
}

int main() {
   int n;
   cin>>n;
 
   cout<<minStepsToOne(n);
   
	return 0;
}
