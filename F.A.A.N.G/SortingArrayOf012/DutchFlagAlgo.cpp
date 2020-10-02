/*
Given an array having n elements representing balls of various colours like red, white or blue, sort them in-place so that balls of the same colour are adjacent, with the colours in the order red, white and blue.
To represent the colour red, white, and blue we will use the integers 0, 1, and 2 respectively.
Note:You are not suppose to use the sort function for this problem.

Input Format
First line contains integer n as size of array. Next n lines contains a single integer as element of array.

Constraints
None

Output Format
Print the balls in order so that balls of same colour are adjacent.

Sample Input
6
2 0 2 1 1 0
Sample Output
0 0 1 1 2 2 

Time Complexity:O(n)
*/
#include<iostream>
using namespace std;
void sortDutchFlagAlgo(int arr[],int n)
{
	int left=0;
	int right=n-1;
	int curr=0;
	while(curr<=right)
	{
		if(arr[curr]==0)
		{
			swap(arr[curr],arr[left]);
			left++;
			curr++;

		}
		else if(arr[curr]==2)
		{
			swap(arr[curr],arr[right]);
			right--;
		}
		else{
			curr++;
		}
	}
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sortDutchFlagAlgo(arr,n);
	return 0;
}
