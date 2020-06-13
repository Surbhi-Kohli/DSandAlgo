/*
for Input:
6
3 34 4 12 5 2
9

Output:
computing for n = 6 and sum = 9
computing for n = 5 and sum = 9
computing for n = 4 and sum = 9
number is greater than sum
computing for n = 3 and sum = 9
computing for n = 2 and sum = 9
number is greater than sum
computing for n = 1 and sum = 9
computing for n = 0 and sum = 9
computing for n = 0 and sum = 6
computing for n = 2 and sum = 5
number is greater than sum
computing for n = 1 and sum = 5
computing for n = 0 and sum = 5
computing for n = 0 and sum = 2
computing for n = 4 and sum = 4
number is greater than sum
computing for n = 3 and sum = 4
computing for n = 2 and sum = 4
number is greater than sum
computing for n = 1 and sum = 4
computing for n = 0 and sum = 4
computing for n = 0 and sum = 1
computing for n = 2 and sum = 0
sum is 0 and n>=0
computing for n = 5 and sum = 7
computing for n = 4 and sum = 7
number is greater than sum
computing for n = 3 and sum = 7
computing for n = 2 and sum = 7
number is greater than sum
computing for n = 1 and sum = 7
computing for n = 0 and sum = 7
computing for n = 0 and sum = 4
computing for n = 2 and sum = 3
number is greater than sum
computing for n = 1 and sum = 3
computing for n = 0 and sum = 3
computing for n = 0 and sum = 0
sum is 0 and n>=0
computing for n = 4 and sum = 2
number is greater than sum
computing for n = 3 and sum = 2
number is greater than sum
computing for n = 2 and sum = 2
number is greater than sum
computing for n = 1 and sum = 2
number is greater than sum
computing for n = 0 and sum = 2
1
Yes  //dp table..although it doesnt get fully filled coz the function doesnt get called for sum=0 and n=1,3,4,5,6
1 0 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 0 
1 0 0 1 0 0 0 0 0 0 
0 0 0 0 1 0 0 1 0 0 
0 0 0 0 1 0 0 1 0 0 
0 0 0 0 0 0 0 1 0 1 
0 0 0 0 0 0 0 0 0 1 


*/

#include <iostream>
#include <cstring>
using namespace std;
bool subsetSumToTarget(int arr[],int n,int sum,int dp[100][100])
{//cout<<"computing for n = "<<n<<" and sum = "<<sum<<endl;

    if(sum==0 &&n>=0)
    {  cout<<"sum is 0 and n>=0"<<endl;
        dp[n][sum]=true;
         return true;
    }
   
    if(n==0 && sum!=0)
    { dp[n][sum]=false;
      return false;   
    }
   
    if(sum!=0 && n!=0 && dp[n][sum]!=0)
    {
        cout<<"Precomputed for dp["<<n<<"]["<<sum<<"]"<<dp[n][sum]<<endl;
    }
    if(arr[n-1]>sum && n-1>=0)
    {  cout<<"number is greater than sum"<<endl;
        dp[n][sum] =subsetSumToTarget(arr,n-1,sum,dp);
    }
    else{
        if(n-1>=0)
        {
             bool op1=subsetSumToTarget(arr,n-1,sum,dp);
    bool op2=subsetSumToTarget(arr,n-1,sum-arr[n-1],dp);
    dp[n][sum]= op1||op2;
        
        }
         
    }
  
    return dp[n][sum];
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int sum;
	cin>>sum;
	int dp[100][100];
	memset(dp,0,sizeof dp);
	bool ans=subsetSumToTarget(arr,n,sum,dp);
	
	cout<<ans<<endl;
	if(ans)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	//we dont get exact dp table although the final ans is correct,this is bcoz certain values
	//in table dont get computed like all vaalues in 1st col shud be 1,but they don't get filled
	//in top down approach
	for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=sum;j++)
	    cout<<dp[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}
