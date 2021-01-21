/*Implementation without extra  couts*/
/*Question: Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

Input Format
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints
1<= n <= 1000
1<= sum <= 10^5
1<= Ai <=10^4

Output Format
Yes, if sum exist No, it sum does not exist

Sample Input
5 10
1 2 3 4 5
Sample Output
Yes*/


#include<iostream>
using namespace std;
bool subsetSum(int arr[],int n,int sum,int **dp)
{
	if(n==0)
	return dp[n][sum]=0;
	if(n!=0 && sum==0)
	return dp[n][sum]=1;

	if(dp[n][sum]!=-1)
	return dp[n][sum];

	else if(arr[n-1]>sum)
	return dp[n][sum]=subsetSum(arr,n-1,sum,dp);

	else
	return dp[n][sum]=subsetSum(arr,n-1,sum,dp)||subsetSum(arr,n-1,sum-arr[n-1],dp);
}
int main() {
	int n,sum;
	cin>>n>>sum;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	int **dp=new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[sum+1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		dp[i][j]=-1;
	}
	if(subsetSum(arr,n,sum,dp))
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}

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
