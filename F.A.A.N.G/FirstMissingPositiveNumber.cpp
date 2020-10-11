/*
Given an array of integers, your task is to find out the first missing positive integer.

Input Format
First line contains a single integer denoting the size of the array.The next line contains N integers

Constraints
N<=100000

Output Format
Print a single line denoting the first missing element

Sample Input                        Sample Input:
4                                   5 
3 4 -1 1                            7 8 9 11 12
Sample Output                       Sample Output 
2                                   1

Approach i.Brute Force Approach:Look for positive integers starting from 1 in the array and return the first missing 
                     Time Complexity:O(n^2)
Approach ii. Maintain a count array/hashmap ,which stores count of each number begining with 1 .Finally check count array and return the index
             which hascount value as 0.But space complexity will be O(max(A)) which can be reduced to O(n) as 1st missing no.
             lies in range 1 to n+1.
Approach iii.
a.Iterate over the array and try placing ith no at i-1th index(as per 0-based indexing).
b.Ignore negative numbers and numbers >n
c.For the first index i that does not have value i+1,we will return i+1;
Time:O(n) Space:O(1)

*/
#include<iostream>
using namespace std;
int firstMissingPositiveNumber(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1])
		{
          swap(arr[i],arr[arr[i]-1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=i+1)
		return i+1;
	}
	return 0;
}
int main () {
	int n;
	cin>>n;
	//cout<<"n is "<<n<<endl;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	  cin>>arr[i];	
	}
	cout<<firstMissingPositiveNumber(arr,n);
	return 0;
}
