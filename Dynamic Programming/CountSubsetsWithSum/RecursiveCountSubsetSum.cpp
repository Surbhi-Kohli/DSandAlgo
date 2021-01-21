/* Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X using recursion. 

Examples:

Input: arr[] = {2, 3, 5, 6, 8, 10}, X = 10
Output: 3
Explanation:
All possible subsets with sum 10 are {2, 3, 5}, {2, 8}, {10}

Input: arr[] = {1, 2, 3, 4, 5}, X = 7
Output: 3
Explanation:
All possible subsets with sum 7 are {2, 5}, {3, 4}, {1, 2, 4}

Time complexity of recursive solution:2^n where n=size of array
*/

#include <iostream> 
using namespace std; 

// Recursive function to return the count 
// of subsets with sum equal to the given value 
int subsetSum(int arr[], int n, int sum) 
{ 
		if (sum==0 && n!=0) 
	return 1;

		if(n==0 && sum!=0)
          return 0;
  if(sum<arr[n-1])
    return subsetSum(arr,n-1,sum);
  else
    return subsetSum(arr,n-1,sum)+subsetSum(arr,n-1,sum-arr[n-1]);
	} 
int main()
{
  int n,sum;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
  cin>>arr[i];
  }
  cin>>sum;
  cout<<subsetSum(arr,n,sum);
}
