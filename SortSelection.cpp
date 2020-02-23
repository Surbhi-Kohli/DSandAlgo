/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning. The algorithm 
maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted
subarray is picked and moved to the sorted subarray.
Time Complexity: O(n^2) as there are two nested loops.

Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
*/

#include <iostream>
using namespace std;

int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int small=arr[0];
int pos=0;
for(int i=0;i<6;i++)
{
      small=arr[i];
      pos=i;
      for(int j=i+1;j<6;j++)
      { 
          if(arr[j]<small)
          {
              small=arr[j];
              pos=j;
          }
      }
       swap(arr[i],arr[pos]);
}
for(int i=0;i<6;i++)
cout<<arr[i]<<" ";
	return 0;
}
