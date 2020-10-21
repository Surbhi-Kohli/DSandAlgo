/*
We are given an array containg n numbers. All the numbers are present twice except for one number which is only present once.
Find the unique number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 2 2 3 3 4 
Sample Output
4
Explanation
4 is present only once

*/
#include<iostream>
using namespace std;
int uniqueNumber(int arr[],int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		
       ans=arr[i]^ans;
	  
	}
	
	return ans;
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<uniqueNumber(arr,n);

	return 0;
}
