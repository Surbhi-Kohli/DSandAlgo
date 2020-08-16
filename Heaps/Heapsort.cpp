/*
HEAP SORT
Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.

*/
#include <iostream>
#include <vector>
using namespace std;
void downheapify(vector<int> &arr,int i,int size)
{
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(left>=size && right>=size)
    return;
    int temp = i;
    if(left<size && arr[left]>arr[temp] )
    {
        temp = left;
    
    }
    if(right<size && arr[right]>arr[temp])
    {
        temp = right;
    }
    if(temp==i)
    return;
    swap(arr[i],arr[temp]);
   // swap(arr[temp],arr[i]);
    downheapify(arr,temp,size);
    
}
void buildHeap_Optimised(vector<int> &arr)
{
    for(int i=arr.size()/2 -1 ;i>=0;i--)
    {
      downheapify(arr,i,arr.size()); 
    }
}
void heapsort(vector <int> &arr)
{
    int heapsize = arr.size();
    buildHeap_Optimised(arr);
   
   while(heapsize>0)
   {
     cout<<arr[0]<<" ";
     swap(arr[0],arr[heapsize-1]);
 
    heapsize=heapsize-1;
 
    downheapify(arr,0,heapsize);
  

   }

    
    
}
int main() {
	// your code goes here
	vector <int> arr;
	int n;
	cin>>n;
	for(int i =0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	heapsort(arr);

	cout<<endl;
	return 0;
}
