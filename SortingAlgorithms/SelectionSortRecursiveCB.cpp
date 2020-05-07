/*
Take as input N, the size of array. Take N more inputs and store that in an array. Write a recursive function which selection sorts the given array. Print all the values in the sorted array.

Input Format
Enter a number N and input N more numbers and store in an array

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
#include<climits>
using namespace std;
void selectionSort(int arr[],int start,int n)
{ 
	if(start==n)
	return;
  int small=INT_MAX,pos=0;
  for(int i=start;i<n;i++)
  {
	  if(arr[i]<small)
	  {
		  small=arr[i];
		  pos=i;
	  }
  }
   cout<<small<<" ";
  swap(arr[pos],arr[start]);
 
  selectionSort(arr,start+1,n);
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	selectionSort(arr,0,n);
	return 0;
}
