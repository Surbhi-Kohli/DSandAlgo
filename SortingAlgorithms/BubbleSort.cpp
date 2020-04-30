/*
Bubble Sort -
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes
Adaptive:Can be made adaptive (if array is sorted in asc order: we can signal with flag that no swap is done,in 1st pass itself,
         So Bubble Sort can be made adaptive)
Usage of Kth Pass:In the Kth pass of bubble sort,we get the kth largest element of an array    
   
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that bubble sorts the array.
Print the elements of sorted array.
1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Bubble sort the array and print the Array.
Input Format
Constraints
N cannot be Negative. Range of Numbers can be between -1000000000 to 100000000.
Output Format
Sample Input
4
2
-18
45
30
Sample Output
-18
2
30
45
Explanation
For each test case write bubble sorting program to sort the elements of the array.
*/

#include<iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      swap(arr[j],arr[j+1]);
    }
  }
   for(int i=0;i<n;i++)
   cout<<arr[i]<<endl;
	return 0;
}
