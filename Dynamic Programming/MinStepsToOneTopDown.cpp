/*
Given a number n, count minimum steps to minimize it to 1 according to the following criteria:

* If n is divisible by 2 then we may reduce n to n/2.
* If n is divisible by 3 then you may reduce n to n/3.
* Decrement n by 1.
Examples:

Input : n = 10
Output : 3

Input : 6
Output : 2

Greedy Approach (Doesn’t work always) :
As per greedy approach we may choose the step that makes n as low as possible and continue the same, till it reaches 1.

If we observe carefully, the greedy strategy doesn’t work here.
Eg: Given n = 10 , Greedy –> 10 /2 = 5 -1 = 4 /2 = 2 /2 = 1 ( 4 steps ).
But the optimal way is –> 10 -1 = 9 /3 = 3 /3 = 1 ( 3 steps ).
So, we must think of dynamic approach for optimal solution.
Dynamic Approach:
For finding minimum steps we have three possibilities for n and they are:

f(n) = 1 + f(n-1)
f(n) = 1 + f(n/2) // if n is divisible by 2
f(n) = 1 + f(n/3) // if n is divisible by 3

*/
#include <iostream>
#include <climits>
using namespace std;
int minStepsToOne(int n,int dp[])
{
    if(n==1)
    return 1;
    
    if(dp[n]!=0)
    return dp[n];
    
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
    {
        op1=minStepsToOne(n/3,dp)+1;
    }
    if(n%2==0)
    {
        op2=minStepsToOne(n/2,dp)+1;
    }
    op3=minStepsToOne(n-1,dp)+1;
    int ans=min(min(op1,op2),op3);
    return dp[n]=ans;
}

int main() {
   int n;
   cin>>n;
   int dp[100]={0};
   cout<<minStepsToOne(n,dp);
   
	return 0;
}

