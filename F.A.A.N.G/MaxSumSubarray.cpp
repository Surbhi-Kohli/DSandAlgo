/*
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

Input Format
The first line consists of number of test cases T. Each test case consists of two lines.
The first line of each testcase contains a single integer N denoting the number of elements for the array A.
The second line of each testcase contains N space separated integers denoting the elements of the array.

Constraints
1 <= N <= 100000

1 <= t <= 20

 -100000000 <= A[i] <= 100000000

Output Format
Output a single integer denoting the maximum subarray sum for each testcase in a new line.

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15
Explanation
For the first testcase, maximum subarray sum is generated by the entire array - 1+2+3+4 = 10
For the second testcase , maximum subarray sum is generated by the subarray {5,10} - 5+10 = 15
*/
#include<iostream>
#include <climits>
using namespace std;
int findMaxSumSubarray(int arr[],int n)
{
	int curr_sum=arr[0];
	int max_sum=arr[0];
	for(int i=1;i<n;i++)
	{
		curr_sum=max(arr[i]+curr_sum,arr[i]);
		max_sum=max(max_sum,curr_sum);
	}
	return max_sum;
}
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{ 
     cin>>n;
	 int arr[n];
	 for(int i=0;i<n;i++)
	 cin>>arr[i];
	cout<<findMaxSumSubarray(arr,n)<<endl;
	}
	return 0;
}
