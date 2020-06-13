/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.

To solve the problem in Pseudo-polynomial time use the Dynamic programming.

So we will create a 2D array of size (arr.size() + 1) * (target + 1) of type boolean. The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’. The approach for the problem is:

if (A[i] > j)
DP[i][j] = DP[i-1][j]
else 
DP[i][j] = DP[i-1][j] OR DP[i-1][sum-A[i]]
This means that if current element has value greater than ‘current sum value’ we will copy the answer for previous cases
And if the current sum value is greater than the ‘ith’ element we will see if any of previous states have already experienced the sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will solve our purpose.
The below simulation will clarify the above approach:

set[]={3, 4, 5, 2}
target=6
 
    0    1    2    3    4    5    6

0   T    F    F    F    F    F    F

3   T    F    F    T    F    F    F
     
4   T    F    F    T    T    F    F   
      
5   T    F    F    T    T    T    F

2   T    F    T    T    T    T    T


*/


#include <iostream>
#include <cstring>
using namespace std;
bool subsetSumToTarget(int arr[],int n,int sum)
{
int dp[n+1][sum+1];
   
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=sum;j++)
       {
           if(i==0 && j!=0)
           dp[i][j]=0;
           else if(i!=0 && j==0)
           dp[i][j]=1;
         else if(i==0 && j==0)
         dp[i][j]=1;
      
           else if(arr[i-1]>j)
           {
               dp[i][j]=dp[i-1][j];
           }
           else{
               dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
           }
       }
   }
   
    
    //printing dp table
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<=sum;j++)
      {
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
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
	

	bool ans=subsetSumToTarget(arr,n,sum);
  if(ans)
  cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
	return 0;
}
