/*
Given an integer array arr, find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

Input Format
Take input N. Next line N contains elements of array, denoting the elements of array.

Constraints
It is assured that the product does not exceed 10^16.

Output Format
print largest product.

Sample Input
15 
1
2
2
1
2
3
4
5
6
1
2
3
4
5
7
Sample Output
2419200

*/
#include<iostream>
using namespace std;
long long int maxProductSubarray(int arr[],int n)
{
  if(n==0)
  return -1;
  
	long long int maxProd=arr[0];
	long long int minProd=arr[0];
	long long int ans=arr[0];
	long long int choice1,choice2,choice3;
	for(int i=1;i<n;i++)
	{    choice1=arr[i];
	     choice2=arr[i]*maxProd;
		 choice3=arr[i]*minProd;
       maxProd=max(choice1,max(choice2,choice3));
	   minProd=min(choice1,min(choice2,choice3));
	   ans=max(ans,maxProd);

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
cout<<maxProductSubarray(arr,n);

	return 0;
}
