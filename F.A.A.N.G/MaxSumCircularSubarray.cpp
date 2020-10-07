/*
Maximum circular subarray sum
Last Updated: 23-07-2020
Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.
Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {-8, -8, -9, -9, -10, -11, -1}
Output: -1


Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1} 
Output:  23 (7 + 6 + 5 - 4 -1 + 10) 

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)

Approach: In this method, modify Kadane’s algorithm to find a minimum contiguous subarray sum and the maximum 
contiguous subarray sum, then check for maximum value among the max_value and the value left after 
subtracting min_value from the total sum.
Time Complexity: O(n), where n is the number of elements in input array.
As only linear traversal of the array is needed.
Auxiliary Space: O(1).
As no extra space is required
*/
#include <iostream>
using namespace std;
int maxSumCircularSubarray(int arr[],int n)
{
    if (n == 1) 
    return arr[0];
  int currSum=arr[0];
  int max_sum=arr[0];
  int totalSum=arr[0];
   int currSumMin=arr[0];
  int minSum=arr[0];
  for(int i=1;i<n;i++)
  {
      totalSum+=arr[i];
      currSum=max(currSum+arr[i],arr[i]);
      max_sum=max(max_sum,currSum);
      currSumMin=min(currSumMin+arr[i],arr[i]);
      minSum=min(currSumMin,minSum);
  }

  
  
  if(minSum==totalSum)
  {
      return max_sum;
  }
  return max(max_sum,totalSum-minSum);
    
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	cout<<maxSumCircularSubarray(arr,n);
	return 0;
}
