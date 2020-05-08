/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning. The algorithm 
maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted
subarray is picked and moved to the sorted subarray.
Time Complexity: O(n^2) as there are two nested loops.
Is Selection sort stable- NO
No. of comparisons:n^2
Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5
Selection sort works by finding the minimum element and then inserting it in its correct
position by swapping with the element which is in the position of this minimum element. This is what makes it unstable.
Swapping might impact in pushing a key(let’s say A) to a position greater than the key(let’s say B) which are equal keys. 
which makes them out of desired order.In the above example 4A was pushed after 4B and after
complete sorting this 4A remains after this 4B. Hence resulting in unstability.
Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
Selection Sort is the sorting algo with min no. of comparisons
Usage of kth pass:In kth pass,we get kth smallest element.
Adaptive:No,Irrespective of whether the list is sorted or not ,its gonna take n^2 time.
*/

#include<iostream>
#include<climits>
using namespace std;
void selectionSort(int arr[],int n)
{
	
	int pos=0;
	int small=0;
	for(int i=0;i<n;i++)
	{
	pos=i;
	small=arr[i];
      for(int j=i+1;j<n;j++)
	  {
		  if(arr[j]<small)
		  {
			  pos=j;
			  small=arr[j];
			 
		  }
	  }
	  swap(arr[i],arr[pos]);
	  
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}

}
int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	selectionSort(arr,n);
	return 0;
}
