/*
You are provided n numbers(both +ve and -ve).Numbers are arranged in circular form.You need to find the maximum sum of consecutive numbers.

Sample Input                   output                     Explanation
7                               22                         Max Sum=22 =12+8-8+9-9+10  
8 -8 9 -9 10 -11 12
  ALgorithm:
  In this problem,there can be 2 cases ,ie ,either the subarray having max sum is obtained in a circular fashion or or subarray havinng 
  max sum is obtained in a non-circular fashion.
  
  The non-circular maximum sum subarray can be obtained directly by Kadane's Algorithm.But the subarray obtained in circular way cannot be simply obtained.
  
  So to solve this problem,we will first calculate the max sum subarray using Kadane Algo,n store it in a variable, say ans1.Then we will invert the sign of every element of the array & again apply the Kadane Algo to calc max sum subarray of the inverted array.
  But we should keep in mind the fact that the max sum of inverted subarray is actually the min sum subarray for the original array.so if we subtract the -ve value of this new sum from the cumulative sum of the original array,we will get another candidate for the answer n name it ans2.Then compare bothe and print the larger one.
 
*/
#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
    int maxSum=INT_MIN,currSum=INT_MIN;
    currSum=arr[0];
    for(int i=1;i<n;i++)
    {
        currSum=max(currSum+arr[i],arr[i]);
        maxSum=max(currSum,maxSum);
    }
    return maxSum;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans1=kadane(arr,n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
	    sum+=arr[i];
	    arr[i]=-1*arr[i];
	}
	int ans2=sum+kadane(arr,n);
if(ans1>ans2)
cout<<ans1;
else
cout<<ans2;
	
	return 0;
}
