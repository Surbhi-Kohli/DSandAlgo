#include <iostream>
using namespace std;
int ladders_problem(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
   
    
    for(int step=1;step<=n;step++)
    {
         for(int i=1;i<=k;i++)
        {
           if(step-i>=0)
           {  
            dp[step]+=dp[step-i];
           }
        }
    }
   
   
    return dp[n];
    
}
int main() {
	int n=4;
	int k=3;
	
	cin>>n>>k;
	cout<<ladders_problem(n,k);
	return 0;
}
