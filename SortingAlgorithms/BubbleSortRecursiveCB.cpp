/*
Take as input N, the size of array. Take N more inputs and store that in an array. Write a recursive function which bubble sorts the given array. Print all the values in the sorted array.

Input Format
Enter a number N and input N more numbers and store it in the array

Constraints
None

Output Format
Display the values of the sorted array

Sample Input
3
3
2
1
Sample Output
1 2 3
*/
#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{  
	if(n==0)
	return;
	int large=arr[0];
	int pos=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>large)
		{
			large=arr[i];
			pos=i;
		}
	}
	swap(arr[n-1],arr[pos]);
	
	bubbleSort(arr,n-1);

}
int main() {
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
      cin>>arr[i];
	}
	bubbleSort(arr,n);
for(int i=0;i<n;i++)
	{
      cout<<arr[i]<<" ";
	}
	return 0;
}
