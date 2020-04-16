/*
HEAP SORT
Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.

*/
#include <iostream>
#include<vector>
using namespace std;
void downHeapify(vector<int> &arr,int i,int size)
{
    int left=2*i+1;
    int right=2*i+2;
    if(left>=size && right>=size)
    return;
    int temp=i;
    if(left<size && arr[left]>arr[temp])
    {
        temp=left;
        
    }
    if(right<size && arr[right]>arr[temp])
    {
        temp=right;
    }
    if(temp==i)
    return;
     swap(arr[temp],arr[i]);
     downHeapify(arr,temp,size);
}
void buildHeapOptimized(vector<int> &arr)
{
    for(int i=arr.size()/2-1;i>=0;i--)
    {
        downHeapify(arr,i,arr.size());
    }
}
void heapSort(vector<int> &arr)
{
    int heapSize=arr.size();
    buildHeapOptimized(arr);
    for(int i=heapSize-1;i>=0;i--)
    {
        swap(arr[0],arr[heapSize-1]);
        heapSize--;
        downHeapify(arr,0,heapSize);
    }
}
int main() {
	vector<int> arr;
	int n;
	cin>>n;  //7
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    arr.push_back(x); //2 1 4 3 6 7 5
	}
	heapSort(arr);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";//1 2 3 4 5 6 7
	cout<<endl;
	
	return 0;
}
