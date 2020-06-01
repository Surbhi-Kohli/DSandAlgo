/*
Find the number of ways to reach the top if a person can take maximum jump of k at each step
E.g If n=4 (No.of steps) and k=3(jumps)
output=7

Implementing below the Top Down Approach with Time Complexity=O(n)
*/
#include <iostream>
using namespace std;
int ladders_problem(int n,int k,int dp[])
{
    if(n==0)
    return 1;
    if(dp[n]!=0)
    return dp[n];
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=ladders_problem(n-i,k,dp);
        }
    }
    dp[n]=ways;
    return ways;
    
}
int main() {
	int n,k;
	int dp[100]={0};
	cin>>n>>k;
	cout<<ladders_problem(n,k,dp);
	return 0;
}
