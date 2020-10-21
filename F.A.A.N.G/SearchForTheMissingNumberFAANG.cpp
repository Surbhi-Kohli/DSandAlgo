/*
Given an array containing n distinct numbers taken from 0, 1, 2, …, n. Find the one that is missing from the array.

Input Format
First line contains integer n as size of array. Next n lines contains a single integer as element of array.

Constraints
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity.

Output Format
Print the required output.

Sample Input
3
3 0 1
Sample Output
2
*/
#include<iostream>
using namespace std;
int searchMissingNumber(int arr[],int n)
{
	int x=0;
	int y=0;
	for(int i=0;i<n;i++)
	{
       x=x^arr[i];
	     y=y^i;
	}
	y=y^n;
	//cout<<x<<endl;
	//cout<<y<<endl;
	return x^y;
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<searchMissingNumber(arr,n);
	return 0;
}
